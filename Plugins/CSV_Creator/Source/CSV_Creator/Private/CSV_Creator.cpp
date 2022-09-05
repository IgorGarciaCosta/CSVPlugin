//All rights reserved to Igor Garcia 2022

#include "CSV_Creator.h"


#define LOCTEXT_NAMESPACE "FCSV_CreatorModule"

void FCSV_CreatorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FCSV_CreatorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}



#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCSV_CreatorModule, CSV_Creator)