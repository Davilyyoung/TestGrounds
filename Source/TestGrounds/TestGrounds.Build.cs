// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestGrounds : ModuleRules
{
	public TestGrounds(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PublicDependencyModuleNames.AddRange(new string[] { "GameplayTasks"});
	}
}
