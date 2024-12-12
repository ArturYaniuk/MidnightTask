// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MidnightTask : ModuleRules
{
	public MidnightTask(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
