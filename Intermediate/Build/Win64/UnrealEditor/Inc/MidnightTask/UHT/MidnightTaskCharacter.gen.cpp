// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MidnightTask/Public/MidnightTaskCharacter.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMidnightTaskCharacter() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AItem_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AMidnightTaskCharacter();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AMidnightTaskCharacter_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
MIDNIGHTTASK_API UClass* Z_Construct_UClass_UTaskCharacterMovementComponent_NoRegister();
MIDNIGHTTASK_API UEnum* Z_Construct_UEnum_MidnightTask_ECharacterState();
MIDNIGHTTASK_API UEnum* Z_Construct_UEnum_MidnightTask_ECombatState();
UPackage* Z_Construct_UPackage__Script_MidnightTask();
// End Cross Module References

// Begin Class AMidnightTaskCharacter Function FinishEquipping
struct Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMidnightTaskCharacter, nullptr, "FinishEquipping", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMidnightTaskCharacter::execFinishEquipping)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishEquipping();
	P_NATIVE_END;
}
// End Class AMidnightTaskCharacter Function FinishEquipping

// Begin Class AMidnightTaskCharacter Function FinishReloading
struct Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics
{
	struct MidnightTaskCharacter_eventFinishReloading_Parms
	{
		AWeapon* Weapon;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Weapon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MidnightTaskCharacter_eventFinishReloading_Parms, Weapon), Z_Construct_UClass_AWeapon_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::NewProp_Weapon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMidnightTaskCharacter, nullptr, "FinishReloading", nullptr, nullptr, Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::MidnightTaskCharacter_eventFinishReloading_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::MidnightTaskCharacter_eventFinishReloading_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMidnightTaskCharacter::execFinishReloading)
{
	P_GET_OBJECT(AWeapon,Z_Param_Weapon);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishReloading(Z_Param_Weapon);
	P_NATIVE_END;
}
// End Class AMidnightTaskCharacter Function FinishReloading

// Begin Class AMidnightTaskCharacter Function GetCustomCharacterMovement
struct Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics
{
	struct MidnightTaskCharacter_eventGetCustomCharacterMovement_Parms
	{
		UTaskCharacterMovementComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MidnightTaskCharacter_eventGetCustomCharacterMovement_Parms, ReturnValue), Z_Construct_UClass_UTaskCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMidnightTaskCharacter, nullptr, "GetCustomCharacterMovement", nullptr, nullptr, Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::MidnightTaskCharacter_eventGetCustomCharacterMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::MidnightTaskCharacter_eventGetCustomCharacterMovement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMidnightTaskCharacter::execGetCustomCharacterMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTaskCharacterMovementComponent**)Z_Param__Result=P_THIS->GetCustomCharacterMovement();
	P_NATIVE_END;
}
// End Class AMidnightTaskCharacter Function GetCustomCharacterMovement

// Begin Class AMidnightTaskCharacter Function GrabClip
struct Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMidnightTaskCharacter, nullptr, "GrabClip", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMidnightTaskCharacter::execGrabClip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GrabClip();
	P_NATIVE_END;
}
// End Class AMidnightTaskCharacter Function GrabClip

// Begin Class AMidnightTaskCharacter Function ReleaseClip
struct Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMidnightTaskCharacter, nullptr, "ReleaseClip", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMidnightTaskCharacter::execReleaseClip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReleaseClip();
	P_NATIVE_END;
}
// End Class AMidnightTaskCharacter Function ReleaseClip

// Begin Class AMidnightTaskCharacter
void AMidnightTaskCharacter::StaticRegisterNativesAMidnightTaskCharacter()
{
	UClass* Class = AMidnightTaskCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FinishEquipping", &AMidnightTaskCharacter::execFinishEquipping },
		{ "FinishReloading", &AMidnightTaskCharacter::execFinishReloading },
		{ "GetCustomCharacterMovement", &AMidnightTaskCharacter::execGetCustomCharacterMovement },
		{ "GrabClip", &AMidnightTaskCharacter::execGrabClip },
		{ "ReleaseClip", &AMidnightTaskCharacter::execReleaseClip },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMidnightTaskCharacter);
UClass* Z_Construct_UClass_AMidnightTaskCharacter_NoRegister()
{
	return AMidnightTaskCharacter::StaticClass();
}
struct Z_Construct_UClass_AMidnightTaskCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MidnightTaskCharacter.h" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Base turn rate, in deg/sec. Other scaling may affect final turn rate\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Base look up/down rate, in deg/sec. Other scaling may affect final rate\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelGoalActor_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The end goal of the test level\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The end goal of the test level" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHoldingJump_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//If the player is continuing to hold jump key\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the player is continuing to hold jump key" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallRunRange_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The extent of the wall trace\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The extent of the wall trace" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallRunGravityScale_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The gravity scale used while wall running\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The gravity scale used while wall running" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultGravityScale_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The gravity scale used when in normal movement\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The gravity scale used when in normal movement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallJumpForce_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The force the player uses to jump off of a wall\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The force the player uses to jump off of a wall" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWallRunning_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Is the player currently running on a wall\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Is the player currently running on a wall" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightWall_MetaData[] = {
		{ "Category", "WallRun" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallHit_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The closest hit wall result\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The closest hit wall result" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousWallHitNormal_MetaData[] = {
		{ "Category", "WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The normal vector of the previously hit wall\n" },
#endif
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The normal vector of the previously hit wall" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isSliding_MetaData[] = {
		{ "Category", "Sliding" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideReloadTime_MetaData[] = {
		{ "Category", "Sliding" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallJump_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipSoundResetTime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Items" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappingItem_MetaData[] = {
		{ "Category", "MidnightTaskCharacter" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthComponent_MetaData[] = {
		{ "Category", "MidnightTaskCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackComponent_MetaData[] = {
		{ "Category", "MidnightTaskCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceHitItem_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceHitItemLastFrame_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Items" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAiming_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquippedWeapon_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFireButtonPressed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Items" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HipFireMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoCapacity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HandSceneComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Scene component to attach to the Character's hand during reloading\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scene component to attach to the Character's hand during reloading" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipTransform_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/MidnightTaskCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelGoalActor;
	static void NewProp_bHoldingJump_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHoldingJump;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallRunRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallRunGravityScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultGravityScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallJumpForce;
	static void NewProp_bWallRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWallRunning;
	static void NewProp_RightWall_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_RightWall;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WallHit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousWallHitNormal;
	static void NewProp_isSliding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isSliding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideReloadTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallJump;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EquipSoundResetTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappingItem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackComponent;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CombatState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CombatState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CharacterState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CharacterState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TraceHitItem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TraceHitItemLastFrame;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Inventory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Inventory;
	static void NewProp_bAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAiming;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EquipMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EquippedWeapon;
	static void NewProp_bFireButtonPressed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFireButtonPressed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HipFireMontage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoCapacity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HandSceneComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClipTransform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMidnightTaskCharacter_FinishEquipping, "FinishEquipping" }, // 671371733
		{ &Z_Construct_UFunction_AMidnightTaskCharacter_FinishReloading, "FinishReloading" }, // 2360732595
		{ &Z_Construct_UFunction_AMidnightTaskCharacter_GetCustomCharacterMovement, "GetCustomCharacterMovement" }, // 888264813
		{ &Z_Construct_UFunction_AMidnightTaskCharacter_GrabClip, "GrabClip" }, // 1568056620
		{ &Z_Construct_UFunction_AMidnightTaskCharacter_ReleaseClip, "ReleaseClip" }, // 3344411238
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMidnightTaskCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, BaseTurnRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseTurnRate_MetaData), NewProp_BaseTurnRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, BaseLookUpRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseLookUpRate_MetaData), NewProp_BaseLookUpRate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_LevelGoalActor = { "LevelGoalActor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, LevelGoalActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelGoalActor_MetaData), NewProp_LevelGoalActor_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bHoldingJump_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->bHoldingJump = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bHoldingJump = { "bHoldingJump", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bHoldingJump_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHoldingJump_MetaData), NewProp_bHoldingJump_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallRunRange = { "WallRunRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, WallRunRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallRunRange_MetaData), NewProp_WallRunRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallRunGravityScale = { "WallRunGravityScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, WallRunGravityScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallRunGravityScale_MetaData), NewProp_WallRunGravityScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_DefaultGravityScale = { "DefaultGravityScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, DefaultGravityScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultGravityScale_MetaData), NewProp_DefaultGravityScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallJumpForce = { "WallJumpForce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, WallJumpForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallJumpForce_MetaData), NewProp_WallJumpForce_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bWallRunning_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->bWallRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bWallRunning = { "bWallRunning", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bWallRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWallRunning_MetaData), NewProp_bWallRunning_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_RightWall_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->RightWall = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_RightWall = { "RightWall", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_RightWall_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightWall_MetaData), NewProp_RightWall_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallHit = { "WallHit", nullptr, (EPropertyFlags)0x0010008000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, WallHit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallHit_MetaData), NewProp_WallHit_MetaData) }; // 4100991306
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_PreviousWallHitNormal = { "PreviousWallHitNormal", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, PreviousWallHitNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousWallHitNormal_MetaData), NewProp_PreviousWallHitNormal_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_isSliding_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->isSliding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_isSliding = { "isSliding", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_isSliding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isSliding_MetaData), NewProp_isSliding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_SlideReloadTime = { "SlideReloadTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, SlideReloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideReloadTime_MetaData), NewProp_SlideReloadTime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallJump = { "WallJump", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, WallJump), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallJump_MetaData), NewProp_WallJump_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquipSoundResetTime = { "EquipSoundResetTime", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, EquipSoundResetTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipSoundResetTime_MetaData), NewProp_EquipSoundResetTime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_OverlappingItem = { "OverlappingItem", nullptr, (EPropertyFlags)0x0040000000020801, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, OverlappingItem), Z_Construct_UClass_AItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappingItem_MetaData), NewProp_OverlappingItem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HealthComponent = { "HealthComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, HealthComponent), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthComponent_MetaData), NewProp_HealthComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_AttackComponent = { "AttackComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, AttackComponent), Z_Construct_UClass_UAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackComponent_MetaData), NewProp_AttackComponent_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CombatState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CombatState = { "CombatState", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, CombatState), Z_Construct_UEnum_MidnightTask_ECombatState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatState_MetaData), NewProp_CombatState_MetaData) }; // 2334205157
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CharacterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, CharacterState), Z_Construct_UEnum_MidnightTask_ECharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterState_MetaData), NewProp_CharacterState_MetaData) }; // 3810304759
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_TraceHitItem = { "TraceHitItem", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, TraceHitItem), Z_Construct_UClass_AItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceHitItem_MetaData), NewProp_TraceHitItem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_TraceHitItemLastFrame = { "TraceHitItemLastFrame", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, TraceHitItemLastFrame), Z_Construct_UClass_AItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceHitItemLastFrame_MetaData), NewProp_TraceHitItemLastFrame_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_Inventory_Inner = { "Inventory", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AItem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_Inventory = { "Inventory", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, Inventory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Inventory_MetaData), NewProp_Inventory_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bAiming_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->bAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bAiming = { "bAiming", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAiming_MetaData), NewProp_bAiming_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_ReloadMontage = { "ReloadMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, ReloadMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadMontage_MetaData), NewProp_ReloadMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquipMontage = { "EquipMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, EquipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipMontage_MetaData), NewProp_EquipMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquippedWeapon = { "EquippedWeapon", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, EquippedWeapon), Z_Construct_UClass_AWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquippedWeapon_MetaData), NewProp_EquippedWeapon_MetaData) };
void Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bFireButtonPressed_SetBit(void* Obj)
{
	((AMidnightTaskCharacter*)Obj)->bFireButtonPressed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bFireButtonPressed = { "bFireButtonPressed", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMidnightTaskCharacter), &Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bFireButtonPressed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFireButtonPressed_MetaData), NewProp_bFireButtonPressed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HipFireMontage = { "HipFireMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, HipFireMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HipFireMontage_MetaData), NewProp_HipFireMontage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_AmmoCapacity = { "AmmoCapacity", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, AmmoCapacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoCapacity_MetaData), NewProp_AmmoCapacity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HandSceneComponent = { "HandSceneComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, HandSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HandSceneComponent_MetaData), NewProp_HandSceneComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_ClipTransform = { "ClipTransform", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMidnightTaskCharacter, ClipTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipTransform_MetaData), NewProp_ClipTransform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMidnightTaskCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_BaseTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_BaseLookUpRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_LevelGoalActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bHoldingJump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallRunRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallRunGravityScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_DefaultGravityScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallJumpForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bWallRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_RightWall,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_PreviousWallHitNormal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_isSliding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_SlideReloadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_WallJump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquipSoundResetTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_OverlappingItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HealthComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_AttackComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CombatState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CombatState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CharacterState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_CharacterState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_TraceHitItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_TraceHitItemLastFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_Inventory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_Inventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_ReloadMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquipMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_EquippedWeapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_bFireButtonPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HipFireMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_AmmoCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_HandSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMidnightTaskCharacter_Statics::NewProp_ClipTransform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMidnightTaskCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_MidnightTask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMidnightTaskCharacter_Statics::ClassParams = {
	&AMidnightTaskCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMidnightTaskCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskCharacter_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMidnightTaskCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AMidnightTaskCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMidnightTaskCharacter()
{
	if (!Z_Registration_Info_UClass_AMidnightTaskCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMidnightTaskCharacter.OuterSingleton, Z_Construct_UClass_AMidnightTaskCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMidnightTaskCharacter.OuterSingleton;
}
template<> MIDNIGHTTASK_API UClass* StaticClass<AMidnightTaskCharacter>()
{
	return AMidnightTaskCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMidnightTaskCharacter);
AMidnightTaskCharacter::~AMidnightTaskCharacter() {}
// End Class AMidnightTaskCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_Public_MidnightTaskCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMidnightTaskCharacter, AMidnightTaskCharacter::StaticClass, TEXT("AMidnightTaskCharacter"), &Z_Registration_Info_UClass_AMidnightTaskCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMidnightTaskCharacter), 3748892741U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_Public_MidnightTaskCharacter_h_2652100538(TEXT("/Script/MidnightTask"),
	Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_Public_MidnightTaskCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Files_My_Works_UE_works_MidnightTask_Source_MidnightTask_Public_MidnightTaskCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
