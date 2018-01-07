// Unreal Engine 4 (UE4) Blueprint Class to read, write and append text files
//
// This code released under the terms and conditions of the GNU GPL3.0 License
// by Mark D. Lougheed - 2018
//
// Original code attributed to Pally Qle:  https://drive.google.com/file/d/0B45Kp15-PhyOT1hyaDM0aUxyVEU/view
// Original code YouTube tutorial: https://www.youtube.com/watch?v=wemG-YI2iag


#include "WaveworksTester.h"
#include "RWTextFile.h"



bool URWTextFile::ReadTxt(FString FileName, FString& ReadText)
{
	return FFileHelper::LoadFileToString(ReadText, *(FPaths::GameDir() + FileName));
}



bool URWTextFile::WriteLn(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB + "\n", *(FPaths::GameDir() + FileNameB));
}




bool URWTextFile::AppendLn(FString SaveTextB, FString FileNameB)
{

	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* handle = file.OpenWrite(*(FPaths::GameDir() + FileNameB), true); // Append
	if (handle)
	{

		handle->Write((const uint8*)TCHAR_TO_ANSI(*SaveTextB), SaveTextB.Len());
		handle->Write((const uint8*)"\n", 1);

		delete handle;
		return true;
	}
	else
		return false;
}


