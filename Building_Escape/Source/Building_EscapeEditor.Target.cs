// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Building_EscapeEditorTarget : TargetRules
{
	public Building_EscapeEditorTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Editor;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

        ExtraModuleNames.Add("Building_Escape");
    }

	//
	// TargetRules interface.
	//
}
