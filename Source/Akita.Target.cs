// Copyright Imo Games

using UnrealBuildTool;
using System.Collections.Generic;

public class AkitaTarget : TargetRules
{
	public AkitaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Akita" } );
	}
}
