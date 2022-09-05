//All rights reserved to Igor Garcia 2022

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSVCreatorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CSV_CREATOR_API UCSVCreatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCSVCreatorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "SaveLoadTextFilePlugin", meta = (Keywords = "Save"))
		static bool SaveText_File(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting);
	UFUNCTION(BlueprintCallable, Category = "SaveLoadTextFilePlugin", meta = (Keywords = "Load"))
		static TArray<FString> LoadText_File(FString Directory, FString FileName);
	UFUNCTION(BlueprintCallable, Category = "SaveLoadTextFilePlugin", meta = (Keywords = "Load"))
		static TArray<FString> LoadANSI_TextFile(FString SaveDirectory, FString FileName);
};
