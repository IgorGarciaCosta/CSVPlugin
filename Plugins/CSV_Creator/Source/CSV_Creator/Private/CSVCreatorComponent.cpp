//All rights reserved to Igor Garcia 2022

#include "CSVCreatorComponent.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

// Sets default values for this component's properties
UCSVCreatorComponent::UCSVCreatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCSVCreatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UCSVCreatorComponent::SaveText_File(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting){
	// Set complete file path
	SaveDirectory += "//";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	
	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}

TArray<FString> UCSVCreatorComponent::LoadText_File(FString SaveDirectory, FString FileName){
	// Set complete file path
	SaveDirectory += "//";
	SaveDirectory += FileName;
	TArray<FString> ResultString;

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory)) {
		//FFileHelper::LoadFileToArray();
		FPlatformFileManager::Get().GetPlatformFile();
		FFileHelper::LoadFileToStringArray(ResultString, *SaveDirectory);
		return ResultString;
	}
	return TArray<FString>();
}

TArray<FString> UCSVCreatorComponent::LoadANSI_TextFile(FString SaveDirectory, FString FileName)
{
	// Set complete file path
	SaveDirectory += "//";
	SaveDirectory += FileName;
	TArray<FString> ReturnValue;

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory)) {
		FFileHelper::LoadANSITextFileToStrings(*SaveDirectory, NULL, ReturnValue);
		return ReturnValue;
	}

	else {
		UE_LOG(LogTemp, Error, TEXT("FILE READING ERROR : File not found."));
	}

	return TArray<FString>();
}

