// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MidnightTask/MidnightTaskGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMidnightTaskGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AMidnightTaskGameMode();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AMidnightTaskGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_MidnightTask();
// End Cross Module References

// Begin Class AMidnightTaskGameMode
void AMidnightTaskGameMode::StaticRegisterNativesAMidnightTaskGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMidnightTaskGameMode);
UClass* Z_Construct_UClass_AMidnightTaskGameMode_NoRegister()
{
	return AMidnightTaskGameMode::StaticClass();
}
struct Z_Construct_UClass_AMidnightTaskGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MidnightTaskGameMode.h" },
		{ "ModuleRelativePath", "MidnightTaskGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMidnightTaskGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMidnightTaskGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_MidnightTask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMidnightTaskGameMode_Statics::ClassParams = {
	&AMidnightTaskGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AMidnightTaskGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMidnightTaskGameMode()
{
	if (!Z_Registration_Info_UClass_AMidnightTaskGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMidnightTaskGameMode.OuterSingleton, Z_Construct_UClass_AMidnightTaskGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMidnightTaskGameMode.OuterSingleton;
}
template<> MIDNIGHTTASK_API UClass* StaticClass<AMidnightTaskGameMode>()
{
	return AMidnightTaskGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMidnightTaskGameMode);
AMidnightTaskGameMode::~AMidnightTaskGameMode() {}
// End Class AMidnightTaskGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_MidnightTaskGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMidnightTaskGameMode, AMidnightTaskGameMode::StaticClass, TEXT("AMidnightTaskGameMode"), &Z_Registration_Info_UClass_AMidnightTaskGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMidnightTaskGameMode), 1108921172U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_MidnightTaskGameMode_h_676007065(TEXT("/Script/MidnightTask"),
	Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_MidnightTaskGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_MidnightTaskGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
