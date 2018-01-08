// Unreal Engine 4 (UE4) Blueprint Class to read, write and append text files
//
// This code released under the terms and conditions of the GNU GPL3.0 License
// by Mark D. Lougheed - 2018
//
// Original code attributed to Pally Qle:  https://drive.google.com/file/d/0B45Kp15-PhyOT1hyaDM0aUxyVEU/view
// Original code YouTube tutorial: https://www.youtube.com/watch?v=wemG-YI2iag

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include <FileHelper.h>
#include <Paths.h>
#include <PlatformFilemanager.h>

#include "RWTextFile.generated.h"



/**
*
*/
UCLASS()
class RWTEXTPROJECT_API URWTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY() public:

		/**
		*	Reads a complete text file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param FileName			File name - in project folder.
		*	@param ReadText			The text in text file
		*/
		UFUNCTION(BlueprintPure, Category = "RWTextFile", meta = (Keywords = "ReadTxt"))
			static bool ReadTxt(FString FileName, FString& ReadText);

		/**
		*	Writes a line of text to a text file.
		*	If existing, overwrites the file. If non-existing, creates the file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param SaveText			Text string to write to file
		*	@param FileName			File name - stored in project folder.
		*/
		UFUNCTION(BlueprintCallable, Category = "RWTextFile", meta = (Keywords = "WriteLn"))
			static bool WriteLn(FString SaveText, FString FileName);

		/**
		*	Appends a line of text to a text file.  If non-existing, creates the file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param SaveText			Text string to append to file
		*	@param FileName			File name - stored in project folder.
		*/
		UFUNCTION(BlueprintCallable, Category = "RWTextFile", meta = (Keywords = "AppendLn"))
			static bool AppendLn(FString SaveText, FString FileName);

};
