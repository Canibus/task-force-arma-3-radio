/* #Folofi
$[
    1.063,
    ["rf7800str",[["0","0","1","1"],"0.0025","0.004","GUI_GRID"],0,1,1],
    [1200,"background",[1,"task_force_radio\rf7800str\rf7800str.paa",["-0.0207812 * safezoneW + safezoneX","-0.5373 * safezoneH + safezoneY","0.418172 * safezoneW","1.551 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1602,"channel_Switch",[1,"",["0.122047 * safezoneW + safezoneX","0.3053 * safezoneH + safezoneY","0.028875 * safezoneW","0.0319 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Previous channel","-1"],[]],
    [1604,"speakers",[1,"",["0.267453 * safezoneW + safezoneX","0.4626 * safezoneH + safezoneY","0.0144375 * safezoneW","0.0605 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Increase volume","-1"],[]],
    [1606,"stereo",[1,"",["0.265391 * safezoneW + safezoneX","0.4186 * safezoneH + safezoneY","0.015 * safezoneW","0.02 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Stereo settings","-1"],[]],
    [1600,"next_channel",[1,"",["0.265906 * safezoneW + safezoneX","0.5814 * safezoneH + safezoneY","0.0113437 * safezoneW","0.0352 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Next channel","-1"],[]],
    [1601,"prev_channel",[1,"",["0.265391 * safezoneW + safezoneX","0.6287 * safezoneH + safezoneY","0.0113437 * safezoneW","0.0319 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Previous channel","-1"],[]],
    [1607,"volume_Switch",[1,"",["0.172578 * safezoneW + safezoneX","0.2899 * safezoneH + safezoneY","0.0314531 * safezoneW","0.0726 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"microdagr_background",[1,"task_force_radio\microdagr\microdagr.paa",["0.263445 * safezoneW + safezoneX","-0.0601101 * safezoneH + safezoneY","0.551203 * safezoneW","1.1484 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"channel_edit",[1,"CH1",["0.481962 * safezoneW + safezoneX","0.450481 * safezoneH + safezoneY","0.0381562 * safezoneW","0.0528 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"edit",[1,"448.9",["0.522161 * safezoneW + safezoneX","0.450481 * safezoneH + safezoneY","0.0613594 * safezoneW","0.0528 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1608,"clear",[1,"CLEAR",["0.480931 * safezoneW + safezoneX","0.534113 * safezoneH + safezoneY","0.0402187 * safezoneW","0.0517 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1609,"enter",[1,"SET",["0.542776 * safezoneW + safezoneX","0.530812 * safezoneH + safezoneY","0.04125 * safezoneW","0.055 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/
class rf7800str_radio_dialog {
    idd = IDD_RF7800STR_RADIO_DIALOG;
    movingEnable = 1;
    controlsBackground[] = { };
    objects[] = { };
    onUnload = "['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'rf7800str_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
    onLoad = QUOTE(if (sunOrMoon < 0.2) then { \
            ((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(rf7800\ui\rf7800str_n.paa)'; \
            ((_this select 0) displayCtrl IDC_MICRODAGR_BACKGROUND) ctrlSetText 'PATHTOF(microdagr\ui\microdagr_n.paa)'; \
        }; \
        _this call TFAR_fnc_updateProgrammatorDialog; \
    );
    controls[]= {
        QUOTE(background),
        QUOTE(channel_Switch),
        QUOTE(stereo),
        QUOTE(next_channel),
        QUOTE(prev_channel),
        QUOTE(speakers),
        QUOTE(volume_Switch),
        QUOTE(microdagr_background),
        QUOTE(channel_edit),
        QUOTE(edit),
        QUOTE(clear),
        QUOTE(enter)
    };

    class background: RscBackPicture {
        idc = IDC_RF7800STR_BACKGROUND;
        text = QPATHTOF(rf7800\ui\rf7800str.paa);
        x = QUOTE(-0.0207812 * safezoneW + safezoneX);
        y = QUOTE(-0.5373 * safezoneH + safezoneY);
        w = QUOTE(0.418172 * safezoneW);
        h = QUOTE(1.551 * safezoneH);
        moving = 1;
    };
    class prev_channel: HiddenButton {
        idc = IDC_RF7800STR_PREV_CHANNEL;
        x = QUOTE(0.265391 * safezoneW + safezoneX);
        y = QUOTE(0.6287 * safezoneH + safezoneY);
        w = QUOTE(0.0113437 * safezoneW);
        h = QUOTE(0.0319 * safezoneH);
        tooltip = ECSTRING(core,previous_channel);
        action = "[0, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class next_channel: HiddenButton {
        idc = IDC_RF7800STR_NEXT_CHANNEL;
        x = QUOTE(0.265906 * safezoneW + safezoneX);
        y = QUOTE(0.5814 * safezoneH + safezoneY);
        w = QUOTE(0.0113437 * safezoneW);
        h = QUOTE(0.0352 * safezoneH);
        tooltip = ECSTRING(core,next_channel);
        action = "[1, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class speakers: HiddenButton {
        idc = IDC_RF7800STR_INCREASE_VOLUME;
        x = QUOTE(0.267453 * safezoneW + safezoneX);
        y = QUOTE(0.4626 * safezoneH + safezoneY);
        w = QUOTE(0.0144375 * safezoneW);
        h = QUOTE(0.0319 * safezoneH);
        tooltip = ECSTRING(core,speakers_settings_true);
        action = "[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
    };
    class stereo: HiddenButton {
        idc = IDC_RF7800STR_STEREO;
        x = QUOTE(0.265391 * safezoneW + safezoneX);
        y = QUOTE(0.4186 * safezoneH + safezoneY);
        w = QUOTE(0.015 * safezoneW);
        h = QUOTE(0.02 * safezoneH);
        action = QUOTE( \
            [ARR_2(TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod TFAR_MAX_STEREO)] call TFAR_fnc_setSwStereo; \
            [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume; \
        );
        tooltip = ECSTRING(core,stereo_settings);
    };
    class channel_Switch: HiddenRotator {
        idc = IDC_RF7800STR_PREV_CHANNEL;
        x = QUOTE(0.122047 * safezoneW + safezoneX);
        y = QUOTE(0.3053 * safezoneH + safezoneY);
        w = QUOTE(0.0288750 * safezoneW);
        h = QUOTE(0.0605 * safezoneH);
        tooltip = ECSTRING(core,rotator_channel);
        onMouseButtonDown ="[_this select 1, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class volume_Switch: HiddenRotator {
        idc = IDC_RF7800STR_SPEAKERS;
        x = QUOTE(0.172578 * safezoneW + safezoneX);
        y = QUOTE(0.2899 * safezoneH + safezoneY);
        w = QUOTE(0.0314531 * safezoneW);
        h = QUOTE(0.0726 * safezoneH);
        tooltip = ECSTRING(core,rotator_volume);
        onMouseButtonDown = "[_this select 1, false] call TFAR_fnc_setVolumeViaDialog;";
    };
    class microdagr_background: RscBackPicture {
        idc = IDC_MICRODAGR_BACKGROUND;
        text = QPATHTOF(microdagr\ui\microdagr.paa);
        x = QUOTE(0.263445 * safezoneW + safezoneX);
        y = QUOTE(-0.0601101 * safezoneH + safezoneY);
        w = QUOTE(0.551203 * safezoneW);
        h = QUOTE(1.1484 * safezoneH);
        moving = 1;
    };
    class channel_edit: RscEditLCD {
        idc = IDC_MICRODAGR_CHANNEL_EDIT;
        text = "CH1";
        x = QUOTE(0.481962 * safezoneW + safezoneX);
        y = QUOTE(0.450481 * safezoneH + safezoneY);
        w = QUOTE(0.0381562 * safezoneW);
        h = QUOTE(0.0528 * safezoneH);
        moving = 1;
        font = "TFAR_font_dots";
        shadow = 2;
        canModify = 0;
        tooltip = ECSTRING(core,current_channel);
    };
    class edit: RscEditLCD {
        idc = IDC_MICRODAGR_EDIT;
        text = "";
        x = QUOTE(0.522161 * safezoneW + safezoneX);
        y = QUOTE(0.450481 * safezoneH + safezoneY);
        w = QUOTE(0.0613594 * safezoneW);
        h = QUOTE(0.0528 * safezoneH);
        moving = 1;
        font = "TFAR_font_dots";
        shadow = 2;
        canModify = 1;
        tooltip = ECSTRING(core,current_freq);
        onKeyUp = QUOTE( \
            if (_this select 1 in [ARR_2(28,156)]) then { \
                [((ctrlParent (_this select 0))) displayCtrl IDC_MICRODAGR_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter; \
            }; \
        );
    };
    class clear: HiddenButton {
        idc = IDC_MICRODAGR_CLEAR;
        text = "CLR";
        x = QUOTE(0.480931 * safezoneW + safezoneX);
        y = QUOTE(0.534113 * safezoneH + safezoneY);
        w = QUOTE(0.0402187 * safezoneW);
        h = QUOTE(0.0517 * safezoneH);
        tooltip = ECSTRING(core,clear_frequency);
        font = "TFAR_font_dots";
        shadow = 2;
        action = QUOTE( \
            ctrlSetText [ARR_2(IDC_MICRODAGR_EDIT,'')]; \
            ctrlSetFocus ((findDisplay IDD_RF7800STR_RADIO_DIALOG) displayCtrl IDC_MICRODAGR_EDIT); \
        );
    };
    class enter: HiddenButton {
        idc = IDC_MICRODAGR_ENTER;
        text = "ENT";
        x = QUOTE(0.542776 * safezoneW + safezoneX);
        y = QUOTE(0.530812 * safezoneH + safezoneY);
        w = QUOTE(0.04125 * safezoneW);
        h = QUOTE(0.055 * safezoneH);
        tooltip = ECSTRING(core,set_frequency);
        font = "TFAR_font_dots";
        shadow = 2;
        onButtonClick = QUOTE([((ctrlParent (_this select 0))) displayCtrl IDC_MICRODAGR_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter;);
        action = "";
    };
};
