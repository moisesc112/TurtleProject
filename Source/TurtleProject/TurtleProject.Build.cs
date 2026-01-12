// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TurtleProject : ModuleRules
{
	public TurtleProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TurtleProject",
			"TurtleProject/Variant_Platforming",
			"TurtleProject/Variant_Platforming/Animation",
			"TurtleProject/Variant_Combat",
			"TurtleProject/Variant_Combat/AI",
			"TurtleProject/Variant_Combat/Animation",
			"TurtleProject/Variant_Combat/Gameplay",
			"TurtleProject/Variant_Combat/Interfaces",
			"TurtleProject/Variant_Combat/UI",
			"TurtleProject/Variant_SideScrolling",
			"TurtleProject/Variant_SideScrolling/AI",
			"TurtleProject/Variant_SideScrolling/Gameplay",
			"TurtleProject/Variant_SideScrolling/Interfaces",
			"TurtleProject/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
