// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class M260424 : ModuleRules
{
	public M260424(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
