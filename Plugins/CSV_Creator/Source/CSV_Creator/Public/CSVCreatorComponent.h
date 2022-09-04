// Fill out your copyright notice in the Description page of Project Settings.

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

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
		static bool SaveText_File(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting);
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Load"))
		static TArray<FString> GetText_File(FString Directory, FString FileName);
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Load"))
		static TArray<FString> GetANSI_TextFile(FString SaveDirectory, FString FileName);
};
