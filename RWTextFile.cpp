// Fill out your copyright notice in the Description page of Project Settings.

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


