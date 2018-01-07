// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RWTextFile.generated.h"

/**
*
*/
UCLASS()
class WAVEWORKSTESTER_API URWTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY() public:

		/**
		*	Reads a complete text file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param FileName			File name - in project folder.
		*	@param ReadText			The text in text file
		*/
		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "ReadTxt"))
			static bool ReadTxt(FString FileName, FString& ReadText);

		/**
		*	Writes a line of text to a text file.
		*	If existing, overwrites the file. If non-existing, creates the file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param SaveText			Text string to write to file
		*	@param FileName			File name - stored in project folder.
		*/
		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "WriteLn"))
			static bool WriteLn(FString SaveText, FString FileName);

		/**
		*	Appends a line of text to a text file.  If non-existing, creates the file.
		*	Returns TRUE if successful. Otherwise FALSE
		*	@param SaveText			Text string to append to file
		*	@param FileName			File name - stored in project folder.
		*/
		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "AppendLn"))
			static bool AppendLn(FString SaveText, FString FileName);

};
