"Resource/UI/BuySubMachineguns_TER.res"
{
	"BuySubMenu"
	{
		"ControlName"		"WizardSubPanel"
		"fieldName"		"BuySubMenu"
		"xpos"			"c-303"
		"ypos"			"c-210"
		"wide"			"606"
		"tall"			"420"
		"autoResize"		"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
	}

	"Title"
	{
		"ControlName"		"Label"
		"fieldName"		"Title"
		"xpos"		"0"
		"ypos"		"6"
		"wide"		"606"
		"tall"		"24"
		"autoResize"		"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_SubmachinegunsLabel"
		"textAlignment"		"center"
		"dulltext"		"0"
		"brighttext"		"0"
		"font"		"MenuTitle"
		"wrap"		"0"
	}

	"ItemInfo"
	{
		"ControlName"		"Panel"
		"fieldName"		"ItemInfo"
		"xpos"		"234"
		"ypos"		"50"
		"wide"		"210"
		"tall"		"250"
		"autoResize"		"3"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
	}

	"mac10"
	{
		"ControlName"		"MouseOverPanelButton"
		"fieldName"		"mac10"
		"xpos"			"20"
		"ypos"			"50"
		"wide"			"200"
		"tall"			"25"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_MAC10"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"command"		"mac10"
		"cost"			"1400"
	}

	"mp5"
	{
		"ControlName"		"MouseOverPanelButton"
		"fieldName"		"mp5"
		"xpos"			"20"
		"ypos"			"76"
		"wide"			"200"
		"tall"			"25"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_MP5"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"command"		"mp5"
		"cost"			"1500"
		"as_restrict"		"1"
	}

	"ump45"
	{
		"ControlName"		"MouseOverPanelButton"
		"fieldName"		"ump45"
		"xpos"			"20"
		"ypos"			"102"
		"wide"			"200"
		"tall"			"25"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_UMP45"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"command"		"ump45"
		"cost"			"1700"
	}

	"p90"
	{
		"ControlName"		"MouseOverPanelButton"
		"fieldName"		"p90"
		"xpos"			"20"
		"ypos"			"128"
		"wide"			"200"
		"tall"			"25"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_P90"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"command"		"p90"
		"cost"			"2350"
		"as_restrict"		"1"
	}

	"CancelButton"
	{
		"ControlName"		"MouseOverPanelButton"
		"fieldName"		"CancelButton"
		"xpos"			"20"
		"ypos"			"284"
		"wide"			"200"
		"tall"			"25"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_Cancel"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"vguicancel"
		"Default"		"1"
	}
	"AutobuyButton"
	{
		"ControlName"		"Button"
		"fieldName"		"AutobuyButton"
		"xpos"		"250"
		"ypos"		"250"
		"wide"		"129"
		"tall"		"26"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuAutobuy"
		"textAlignment"		"center"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"autobuy"
		"Default"		"0"
	}
	"RebuyButton"
	{
		"ControlName"		"Button"
		"fieldName"		"RebuyButton"
		"xpos"		"250"
		"ypos"		"275"
		"wide"		"129"
		"tall"		"26"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuRebuy"
		"textAlignment"		"center"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"rebuy"
		"Default"		"0"
	}
	"BuyPresetButtonA"
	{
		"ControlName"		"Button"
		"fieldName"		"BuyPresetButtonA"
		"xpos"		"405"
		"ypos"		"50"
		"wide"		"175"
		"tall"		"38"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuPreset1"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"cl_buy_favorite 1"
		"command_set"		"cl_buy_favorite_query_set 1"
		"Default"		"0"
	}
	"BuyPresetButtonB"
	{
		"ControlName"		"Button"
		"fieldName"		"BuyPresetButtonB"
		"xpos"		"405"
		"ypos"		"90"
		"wide"		"175"
		"tall"		"38"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuPreset2"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"cl_buy_favorite 2"
		"command_set"		"cl_buy_favorite_query_set 2"
		"Default"		"0"
	}
	"BuyPresetButtonC"
	{
		"ControlName"		"Button"
		"fieldName"		"BuyPresetButtonC"
		"xpos"		"405"
		"ypos"		"130"
		"wide"		"175"
		"tall"		"38"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuPreset3"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"cl_buy_favorite 3"
		"command_set"		"cl_buy_favorite_query_set 3"
		"Default"		"0"
	}
	"BuyPresetButtonD"
	{
		"ControlName"		"Button"
		"fieldName"		"BuyPresetButtonD"
		"xpos"		"405"
		"ypos"		"170"
		"wide"		"175"
		"tall"		"38"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuPreset4"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"cl_buy_favorite 4"
		"command_set"		"cl_buy_favorite_query_set 4"
		"Default"		"0"
	}
	"BuyPresetButtonE"
	{
		"ControlName"		"Button"
		"fieldName"		"BuyPresetButtonE"
		"xpos"		"405"
		"ypos"		"210"
		"wide"		"175"
		"tall"		"38"
		"autoResize"		"0"
		"pinCorner"		"2"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#Cstrike_BuyMenuPreset5"
		"textAlignment"		"west"
		"dulltext"		"0"
		"brighttext"		"0"
		"Command"		"cl_buy_favorite 5"
		"command_set"		"cl_buy_favorite_query_set 5"
		"Default"		"0"
	}
	"loadoutPanel"
	{
		"ControlName"		"Panel"
		"fieldName"		"loadoutPanel"
		"xpos"		"20"
		"ypos"		"335"
		"wide"		"562"
		"tall"		"60"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
	}
}
