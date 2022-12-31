    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtP.PWM_Period
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.PWM1_Period
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.BandLimitedWhiteNoise1_seed
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.BandLimitedWhiteNoise_seed
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.WrapToZero_Threshold
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 166;
            section.data(166)  = dumData; %prealloc

                    ;% rtP.Integrator1_IC
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Gain
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Integrator_IC
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Integrator1_IC_aul1jddy20
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.u_Gain
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Gain_Gain
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.u_Gain_fqvbril3va
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Saturation_UpperSat
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Saturation_LowerSat
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Gain_Gain_an1pdnuefr
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Switch_Threshold
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Switch1_Threshold
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Integrator3_IC
                    section.data(13).logicalSrcIdx = 17;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Integrator2_IC
                    section.data(14).logicalSrcIdx = 18;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.u_Gain_b4npwylgl1
                    section.data(15).logicalSrcIdx = 19;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Integrator_IC_edh1bx55d3
                    section.data(16).logicalSrcIdx = 20;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.u_Gain_lklkiehjn3
                    section.data(17).logicalSrcIdx = 21;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.u_Gain_pcqi2zh5ks
                    section.data(18).logicalSrcIdx = 22;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.WhiteNoise_Mean
                    section.data(19).logicalSrcIdx = 23;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.WhiteNoise_StdDev
                    section.data(20).logicalSrcIdx = 24;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.Output_Gain
                    section.data(21).logicalSrcIdx = 25;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.Gain_Gain_iih4ui3cnf
                    section.data(22).logicalSrcIdx = 26;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Integrator1_IC_p55ptnmnhu
                    section.data(23).logicalSrcIdx = 27;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP._Gain
                    section.data(24).logicalSrcIdx = 28;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Integrator_IC_ltzbm21qdw
                    section.data(25).logicalSrcIdx = 29;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.ASCIIEncode_P1_Size
                    section.data(26).logicalSrcIdx = 30;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.ASCIIEncode_P1
                    section.data(27).logicalSrcIdx = 31;
                    section.data(27).dtTransOffset = 27;

                    ;% rtP.ASCIIEncode_P2_Size
                    section.data(28).logicalSrcIdx = 32;
                    section.data(28).dtTransOffset = 31;

                    ;% rtP.ASCIIEncode_P2
                    section.data(29).logicalSrcIdx = 33;
                    section.data(29).dtTransOffset = 33;

                    ;% rtP.ASCIIEncode_P3_Size
                    section.data(30).logicalSrcIdx = 34;
                    section.data(30).dtTransOffset = 34;

                    ;% rtP.ASCIIEncode_P3
                    section.data(31).logicalSrcIdx = 35;
                    section.data(31).dtTransOffset = 36;

                    ;% rtP.ASCIIEncode_P4_Size
                    section.data(32).logicalSrcIdx = 36;
                    section.data(32).dtTransOffset = 37;

                    ;% rtP.ASCIIEncode_P4
                    section.data(33).logicalSrcIdx = 37;
                    section.data(33).dtTransOffset = 39;

                    ;% rtP.ASCIIEncode1_P1_Size
                    section.data(34).logicalSrcIdx = 38;
                    section.data(34).dtTransOffset = 40;

                    ;% rtP.ASCIIEncode1_P1
                    section.data(35).logicalSrcIdx = 39;
                    section.data(35).dtTransOffset = 42;

                    ;% rtP.ASCIIEncode1_P2_Size
                    section.data(36).logicalSrcIdx = 40;
                    section.data(36).dtTransOffset = 46;

                    ;% rtP.ASCIIEncode1_P2
                    section.data(37).logicalSrcIdx = 41;
                    section.data(37).dtTransOffset = 48;

                    ;% rtP.ASCIIEncode1_P3_Size
                    section.data(38).logicalSrcIdx = 42;
                    section.data(38).dtTransOffset = 49;

                    ;% rtP.ASCIIEncode1_P3
                    section.data(39).logicalSrcIdx = 43;
                    section.data(39).dtTransOffset = 51;

                    ;% rtP.ASCIIEncode1_P4_Size
                    section.data(40).logicalSrcIdx = 44;
                    section.data(40).dtTransOffset = 52;

                    ;% rtP.ASCIIEncode1_P4
                    section.data(41).logicalSrcIdx = 45;
                    section.data(41).dtTransOffset = 54;

                    ;% rtP.Saturation_UpperSat_gxwe5io0f4
                    section.data(42).logicalSrcIdx = 46;
                    section.data(42).dtTransOffset = 55;

                    ;% rtP.Saturation_LowerSat_ggci1m3fwr
                    section.data(43).logicalSrcIdx = 47;
                    section.data(43).dtTransOffset = 56;

                    ;% rtP.Saturation_UpperSat_nctbwbdtp3
                    section.data(44).logicalSrcIdx = 48;
                    section.data(44).dtTransOffset = 57;

                    ;% rtP.Saturation_LowerSat_khkejnf40e
                    section.data(45).logicalSrcIdx = 49;
                    section.data(45).dtTransOffset = 58;

                    ;% rtP.ASCIIDecode_P1_Size
                    section.data(46).logicalSrcIdx = 50;
                    section.data(46).dtTransOffset = 59;

                    ;% rtP.ASCIIDecode_P1
                    section.data(47).logicalSrcIdx = 51;
                    section.data(47).dtTransOffset = 61;

                    ;% rtP.ASCIIDecode_P2_Size
                    section.data(48).logicalSrcIdx = 52;
                    section.data(48).dtTransOffset = 64;

                    ;% rtP.ASCIIDecode_P2
                    section.data(49).logicalSrcIdx = 53;
                    section.data(49).dtTransOffset = 66;

                    ;% rtP.ASCIIDecode_P3_Size
                    section.data(50).logicalSrcIdx = 54;
                    section.data(50).dtTransOffset = 67;

                    ;% rtP.ASCIIDecode_P3
                    section.data(51).logicalSrcIdx = 55;
                    section.data(51).dtTransOffset = 69;

                    ;% rtP.ASCIIDecode1_P1_Size
                    section.data(52).logicalSrcIdx = 56;
                    section.data(52).dtTransOffset = 70;

                    ;% rtP.ASCIIDecode1_P1
                    section.data(53).logicalSrcIdx = 57;
                    section.data(53).dtTransOffset = 72;

                    ;% rtP.ASCIIDecode1_P2_Size
                    section.data(54).logicalSrcIdx = 58;
                    section.data(54).dtTransOffset = 75;

                    ;% rtP.ASCIIDecode1_P2
                    section.data(55).logicalSrcIdx = 59;
                    section.data(55).dtTransOffset = 77;

                    ;% rtP.ASCIIDecode1_P3_Size
                    section.data(56).logicalSrcIdx = 60;
                    section.data(56).dtTransOffset = 78;

                    ;% rtP.ASCIIDecode1_P3
                    section.data(57).logicalSrcIdx = 61;
                    section.data(57).dtTransOffset = 80;

                    ;% rtP.ASCIIDecode2_P1_Size
                    section.data(58).logicalSrcIdx = 62;
                    section.data(58).dtTransOffset = 81;

                    ;% rtP.ASCIIDecode2_P1
                    section.data(59).logicalSrcIdx = 63;
                    section.data(59).dtTransOffset = 83;

                    ;% rtP.ASCIIDecode2_P2_Size
                    section.data(60).logicalSrcIdx = 64;
                    section.data(60).dtTransOffset = 86;

                    ;% rtP.ASCIIDecode2_P2
                    section.data(61).logicalSrcIdx = 65;
                    section.data(61).dtTransOffset = 88;

                    ;% rtP.ASCIIDecode2_P3_Size
                    section.data(62).logicalSrcIdx = 66;
                    section.data(62).dtTransOffset = 89;

                    ;% rtP.ASCIIDecode2_P3
                    section.data(63).logicalSrcIdx = 67;
                    section.data(63).dtTransOffset = 91;

                    ;% rtP.ASCIIDecode3_P1_Size
                    section.data(64).logicalSrcIdx = 68;
                    section.data(64).dtTransOffset = 92;

                    ;% rtP.ASCIIDecode3_P1
                    section.data(65).logicalSrcIdx = 69;
                    section.data(65).dtTransOffset = 94;

                    ;% rtP.ASCIIDecode3_P2_Size
                    section.data(66).logicalSrcIdx = 70;
                    section.data(66).dtTransOffset = 97;

                    ;% rtP.ASCIIDecode3_P2
                    section.data(67).logicalSrcIdx = 71;
                    section.data(67).dtTransOffset = 99;

                    ;% rtP.ASCIIDecode3_P3_Size
                    section.data(68).logicalSrcIdx = 72;
                    section.data(68).dtTransOffset = 100;

                    ;% rtP.ASCIIDecode3_P3
                    section.data(69).logicalSrcIdx = 73;
                    section.data(69).dtTransOffset = 102;

                    ;% rtP.ASCIIDecode4_P1_Size
                    section.data(70).logicalSrcIdx = 74;
                    section.data(70).dtTransOffset = 103;

                    ;% rtP.ASCIIDecode4_P1
                    section.data(71).logicalSrcIdx = 75;
                    section.data(71).dtTransOffset = 105;

                    ;% rtP.ASCIIDecode4_P2_Size
                    section.data(72).logicalSrcIdx = 76;
                    section.data(72).dtTransOffset = 108;

                    ;% rtP.ASCIIDecode4_P2
                    section.data(73).logicalSrcIdx = 77;
                    section.data(73).dtTransOffset = 110;

                    ;% rtP.ASCIIDecode4_P3_Size
                    section.data(74).logicalSrcIdx = 78;
                    section.data(74).dtTransOffset = 111;

                    ;% rtP.ASCIIDecode4_P3
                    section.data(75).logicalSrcIdx = 79;
                    section.data(75).dtTransOffset = 113;

                    ;% rtP.ASCIIDecode5_P1_Size
                    section.data(76).logicalSrcIdx = 80;
                    section.data(76).dtTransOffset = 114;

                    ;% rtP.ASCIIDecode5_P1
                    section.data(77).logicalSrcIdx = 81;
                    section.data(77).dtTransOffset = 116;

                    ;% rtP.ASCIIDecode5_P2_Size
                    section.data(78).logicalSrcIdx = 82;
                    section.data(78).dtTransOffset = 119;

                    ;% rtP.ASCIIDecode5_P2
                    section.data(79).logicalSrcIdx = 83;
                    section.data(79).dtTransOffset = 121;

                    ;% rtP.ASCIIDecode5_P3_Size
                    section.data(80).logicalSrcIdx = 84;
                    section.data(80).dtTransOffset = 122;

                    ;% rtP.ASCIIDecode5_P3
                    section.data(81).logicalSrcIdx = 85;
                    section.data(81).dtTransOffset = 124;

                    ;% rtP.WhiteNoise_Mean_cm2ydxtnvw
                    section.data(82).logicalSrcIdx = 86;
                    section.data(82).dtTransOffset = 125;

                    ;% rtP.WhiteNoise_StdDev_iarpuhegie
                    section.data(83).logicalSrcIdx = 87;
                    section.data(83).dtTransOffset = 126;

                    ;% rtP.Output_Gain_kseoije4vl
                    section.data(84).logicalSrcIdx = 88;
                    section.data(84).dtTransOffset = 127;

                    ;% rtP.Gain1_Gain
                    section.data(85).logicalSrcIdx = 89;
                    section.data(85).dtTransOffset = 128;

                    ;% rtP.VariableTimeDelay1_MaxDelay
                    section.data(86).logicalSrcIdx = 90;
                    section.data(86).dtTransOffset = 129;

                    ;% rtP.VariableTimeDelay1_InitOutput
                    section.data(87).logicalSrcIdx = 91;
                    section.data(87).dtTransOffset = 130;

                    ;% rtP.VariableTimeDelay_MaxDelay
                    section.data(88).logicalSrcIdx = 92;
                    section.data(88).dtTransOffset = 131;

                    ;% rtP.VariableTimeDelay_InitOutput
                    section.data(89).logicalSrcIdx = 93;
                    section.data(89).dtTransOffset = 132;

                    ;% rtP.Switch2_Threshold
                    section.data(90).logicalSrcIdx = 94;
                    section.data(90).dtTransOffset = 133;

                    ;% rtP.Switch3_Threshold
                    section.data(91).logicalSrcIdx = 95;
                    section.data(91).dtTransOffset = 134;

                    ;% rtP.Gain_Gain_gqjpcqg2pu
                    section.data(92).logicalSrcIdx = 96;
                    section.data(92).dtTransOffset = 135;

                    ;% rtP.Gain_Gain_oodfwwlgw5
                    section.data(93).logicalSrcIdx = 97;
                    section.data(93).dtTransOffset = 136;

                    ;% rtP.Gain_dcquyu5zec
                    section.data(94).logicalSrcIdx = 98;
                    section.data(94).dtTransOffset = 137;

                    ;% rtP.u_Gain_i3zbnwm4y2
                    section.data(95).logicalSrcIdx = 99;
                    section.data(95).dtTransOffset = 138;

                    ;% rtP.u_Gain_pqq0pxqop5
                    section.data(96).logicalSrcIdx = 100;
                    section.data(96).dtTransOffset = 139;

                    ;% rtP.u_Gain_m2whdurejq
                    section.data(97).logicalSrcIdx = 101;
                    section.data(97).dtTransOffset = 140;

                    ;% rtP.u_Gain_iw0b3pebia
                    section.data(98).logicalSrcIdx = 102;
                    section.data(98).dtTransOffset = 141;

                    ;% rtP.Gain_o44e2s1oov
                    section.data(99).logicalSrcIdx = 103;
                    section.data(99).dtTransOffset = 142;

                    ;% rtP._Gain_igqv4gz3am
                    section.data(100).logicalSrcIdx = 104;
                    section.data(100).dtTransOffset = 143;

                    ;% rtP._Gain_ezpdmdm44b
                    section.data(101).logicalSrcIdx = 105;
                    section.data(101).dtTransOffset = 144;

                    ;% rtP._Gain_ocd1v2y2wv
                    section.data(102).logicalSrcIdx = 106;
                    section.data(102).dtTransOffset = 145;

                    ;% rtP._Gain_jqvyrpyhlw
                    section.data(103).logicalSrcIdx = 107;
                    section.data(103).dtTransOffset = 146;

                    ;% rtP._Gain_dq53dumoid
                    section.data(104).logicalSrcIdx = 108;
                    section.data(104).dtTransOffset = 147;

                    ;% rtP._Gain_a2p4tfbpm4
                    section.data(105).logicalSrcIdx = 109;
                    section.data(105).dtTransOffset = 148;

                    ;% rtP._Gain_iaiof1ych2
                    section.data(106).logicalSrcIdx = 110;
                    section.data(106).dtTransOffset = 149;

                    ;% rtP._Gain_ec3r4dr3zn
                    section.data(107).logicalSrcIdx = 111;
                    section.data(107).dtTransOffset = 150;

                    ;% rtP._Gain_nwjfwxlfng
                    section.data(108).logicalSrcIdx = 112;
                    section.data(108).dtTransOffset = 151;

                    ;% rtP.Gain_c5zyi33wrb
                    section.data(109).logicalSrcIdx = 113;
                    section.data(109).dtTransOffset = 152;

                    ;% rtP._Gain_fl03d5u1kp
                    section.data(110).logicalSrcIdx = 114;
                    section.data(110).dtTransOffset = 153;

                    ;% rtP.u_Gain_gp00rtkqtb
                    section.data(111).logicalSrcIdx = 115;
                    section.data(111).dtTransOffset = 154;

                    ;% rtP._Gain_ex1r0c12fd
                    section.data(112).logicalSrcIdx = 116;
                    section.data(112).dtTransOffset = 155;

                    ;% rtP.Gain_jvjms1w3ad
                    section.data(113).logicalSrcIdx = 117;
                    section.data(113).dtTransOffset = 156;

                    ;% rtP._Gain_lcqhixjq0z
                    section.data(114).logicalSrcIdx = 118;
                    section.data(114).dtTransOffset = 157;

                    ;% rtP._Gain_ni4xvt1vxz
                    section.data(115).logicalSrcIdx = 119;
                    section.data(115).dtTransOffset = 158;

                    ;% rtP.u_Gain_jngffoyzbc
                    section.data(116).logicalSrcIdx = 120;
                    section.data(116).dtTransOffset = 159;

                    ;% rtP.u_Gain_nudgobpj1r
                    section.data(117).logicalSrcIdx = 121;
                    section.data(117).dtTransOffset = 160;

                    ;% rtP.u_Gain_mdaasjyeq0
                    section.data(118).logicalSrcIdx = 122;
                    section.data(118).dtTransOffset = 161;

                    ;% rtP.a_Value
                    section.data(119).logicalSrcIdx = 123;
                    section.data(119).dtTransOffset = 162;

                    ;% rtP.a1_Value
                    section.data(120).logicalSrcIdx = 124;
                    section.data(120).dtTransOffset = 163;

                    ;% rtP.a2_Value
                    section.data(121).logicalSrcIdx = 125;
                    section.data(121).dtTransOffset = 164;

                    ;% rtP.a3_Value
                    section.data(122).logicalSrcIdx = 126;
                    section.data(122).dtTransOffset = 165;

                    ;% rtP.a4_Value
                    section.data(123).logicalSrcIdx = 127;
                    section.data(123).dtTransOffset = 166;

                    ;% rtP.a5_Value
                    section.data(124).logicalSrcIdx = 128;
                    section.data(124).dtTransOffset = 167;

                    ;% rtP.a6_Value
                    section.data(125).logicalSrcIdx = 129;
                    section.data(125).dtTransOffset = 168;

                    ;% rtP.a7_Value
                    section.data(126).logicalSrcIdx = 130;
                    section.data(126).dtTransOffset = 169;

                    ;% rtP.b_Value
                    section.data(127).logicalSrcIdx = 131;
                    section.data(127).dtTransOffset = 170;

                    ;% rtP.c_Value
                    section.data(128).logicalSrcIdx = 132;
                    section.data(128).dtTransOffset = 171;

                    ;% rtP.constant_Value
                    section.data(129).logicalSrcIdx = 133;
                    section.data(129).dtTransOffset = 172;

                    ;% rtP.constant1_Value
                    section.data(130).logicalSrcIdx = 134;
                    section.data(130).dtTransOffset = 173;

                    ;% rtP.constant2_Value
                    section.data(131).logicalSrcIdx = 135;
                    section.data(131).dtTransOffset = 174;

                    ;% rtP.constant3_Value
                    section.data(132).logicalSrcIdx = 136;
                    section.data(132).dtTransOffset = 175;

                    ;% rtP.d_Value
                    section.data(133).logicalSrcIdx = 137;
                    section.data(133).dtTransOffset = 176;

                    ;% rtP.e_Value
                    section.data(134).logicalSrcIdx = 138;
                    section.data(134).dtTransOffset = 177;

                    ;% rtP.timestep_Value
                    section.data(135).logicalSrcIdx = 139;
                    section.data(135).dtTransOffset = 178;

                    ;% rtP.timestep1_Value
                    section.data(136).logicalSrcIdx = 140;
                    section.data(136).dtTransOffset = 179;

                    ;% rtP.timestep2_Value
                    section.data(137).logicalSrcIdx = 141;
                    section.data(137).dtTransOffset = 180;

                    ;% rtP.timestep3_Value
                    section.data(138).logicalSrcIdx = 142;
                    section.data(138).dtTransOffset = 181;

                    ;% rtP._Value
                    section.data(139).logicalSrcIdx = 143;
                    section.data(139).dtTransOffset = 182;

                    ;% rtP.Value
                    section.data(140).logicalSrcIdx = 144;
                    section.data(140).dtTransOffset = 183;

                    ;% rtP._Value_fcrkhd1pwn
                    section.data(141).logicalSrcIdx = 145;
                    section.data(141).dtTransOffset = 184;

                    ;% rtP.Value_dfptlknwpi
                    section.data(142).logicalSrcIdx = 146;
                    section.data(142).dtTransOffset = 185;

                    ;% rtP.constant3_Value_d4zn1mb3f1
                    section.data(143).logicalSrcIdx = 147;
                    section.data(143).dtTransOffset = 186;

                    ;% rtP.constant3_Value_gdybbqcsvv
                    section.data(144).logicalSrcIdx = 148;
                    section.data(144).dtTransOffset = 187;

                    ;% rtP.constant3_Value_e1gwiy1pb3
                    section.data(145).logicalSrcIdx = 149;
                    section.data(145).dtTransOffset = 188;

                    ;% rtP.constant3_Value_bufvhyvmaf
                    section.data(146).logicalSrcIdx = 150;
                    section.data(146).dtTransOffset = 189;

                    ;% rtP.Value_mdbqjrgdok
                    section.data(147).logicalSrcIdx = 151;
                    section.data(147).dtTransOffset = 190;

                    ;% rtP.Constant_Value
                    section.data(148).logicalSrcIdx = 152;
                    section.data(148).dtTransOffset = 191;

                    ;% rtP.Constant1_Value
                    section.data(149).logicalSrcIdx = 153;
                    section.data(149).dtTransOffset = 192;

                    ;% rtP.open_AOAdegree_Value
                    section.data(150).logicalSrcIdx = 154;
                    section.data(150).dtTransOffset = 193;

                    ;% rtP.close_AOAdegree_Value
                    section.data(151).logicalSrcIdx = 155;
                    section.data(151).dtTransOffset = 194;

                    ;% rtP.Constant_Value_ndti5ul2ir
                    section.data(152).logicalSrcIdx = 156;
                    section.data(152).dtTransOffset = 195;

                    ;% rtP.Constant1_Value_gwfubws50w
                    section.data(153).logicalSrcIdx = 157;
                    section.data(153).dtTransOffset = 196;

                    ;% rtP.open_AOAdegree_Value_puyaicdqcr
                    section.data(154).logicalSrcIdx = 158;
                    section.data(154).dtTransOffset = 197;

                    ;% rtP.close_AOAdegree_Value_h2ko2tzd3h
                    section.data(155).logicalSrcIdx = 159;
                    section.data(155).dtTransOffset = 198;

                    ;% rtP.Constant_Value_iq4hlvezb4
                    section.data(156).logicalSrcIdx = 160;
                    section.data(156).dtTransOffset = 199;

                    ;% rtP.Constant1_Value_bfs2kyqhyj
                    section.data(157).logicalSrcIdx = 161;
                    section.data(157).dtTransOffset = 200;

                    ;% rtP.open_AOAdegree_Value_bru0w4josw
                    section.data(158).logicalSrcIdx = 162;
                    section.data(158).dtTransOffset = 201;

                    ;% rtP.close_AOAdegree_Value_crud0nlfli
                    section.data(159).logicalSrcIdx = 163;
                    section.data(159).dtTransOffset = 202;

                    ;% rtP.Constant_Value_dbb4dojqmp
                    section.data(160).logicalSrcIdx = 164;
                    section.data(160).dtTransOffset = 203;

                    ;% rtP.Constant1_Value_fqnw4iunxo
                    section.data(161).logicalSrcIdx = 165;
                    section.data(161).dtTransOffset = 204;

                    ;% rtP.open_AOAdegree_Value_a135evdloz
                    section.data(162).logicalSrcIdx = 166;
                    section.data(162).dtTransOffset = 205;

                    ;% rtP.close_AOAdegree_Value_mqej5anoke
                    section.data(163).logicalSrcIdx = 167;
                    section.data(163).dtTransOffset = 206;

                    ;% rtP.Ncm_Value
                    section.data(164).logicalSrcIdx = 168;
                    section.data(164).dtTransOffset = 207;

                    ;% rtP.Ncm1_Value
                    section.data(165).logicalSrcIdx = 169;
                    section.data(165).dtTransOffset = 208;

                    ;% rtP._Value_ihbzrbcjcd
                    section.data(166).logicalSrcIdx = 170;
                    section.data(166).dtTransOffset = 209;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.Output_InitialCondition
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.FixPtConstant_Value
                    section.data(2).logicalSrcIdx = 172;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant_Value_dsvukcvkuu
                    section.data(3).logicalSrcIdx = 173;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 22;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% rtB.a405zozv5t
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.buugn1y4kg
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.m0fvlyj223
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.mqpvdapacf
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.frqdqeq5gg
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.itbqmhqgrz
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.e4k3uwbbqo
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.oj1fmvrj3c
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.i54d4oicep
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.ku0cdrtwff
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.bwgs3crvzk
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.exrmi0ldfj
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.be3gvejel2
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.lonvbzqzr1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.firups0wj2
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.mjlpzkqz1n
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.etvoly05ch
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.gkuq4mb5x4
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.gg1qdr0ca0
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.fn1r3pr3py
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.gyqrec4ceq
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.a3plauwk5y
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.facwgsdsd1
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.ha2jxgqr02
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.htcqv5fxtd
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.a43mlssova
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.goi1oiwwan
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.bzfi1eqihy
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.k2tv1y1gn5
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.mfao3xhxn3
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.hyhxikiti2
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.bkayq3jpfr
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.arjieh1qz2
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.b0atyboa0x
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.ov41nszkfe
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.ff3s1fh5wh
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.crmbrbsz2x
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.hhfhv1g453
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.pdvh3wfivp
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.n4zpljasue
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.m0wxbflasp
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.ipbondrkcl
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.jqaxfynhz3
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.oqvlx0tggb
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.klwp3o5znj
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.omvc30ouxs
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.n0yzexgdyh
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.atbvn2nrjn
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.d3mqkoc1ln
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.mnvxcylwkr
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 49;

                    ;% rtB.pgeeu4rvpl
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 50;

                    ;% rtB.aeq3t23mz4
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 51;

                    ;% rtB.fywlqxnu4j
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 52;

                    ;% rtB.nzqgm2nb3k
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 53;

                    ;% rtB.iewiqnu5gm
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 54;

                    ;% rtB.c1l0t1ppoz
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 55;

                    ;% rtB.p4ublk43y4
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 56;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.otnxjer3d0
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtB.hjr01anyo4
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.f3ybeuoetm
                    section.data(2).logicalSrcIdx = 59;
                    section.data(2).dtTransOffset = 128;

                    ;% rtB.iar4fhawbp
                    section.data(3).logicalSrcIdx = 60;
                    section.data(3).dtTransOffset = 256;

                    ;% rtB.ixgganvvtz
                    section.data(4).logicalSrcIdx = 61;
                    section.data(4).dtTransOffset = 512;

                    ;% rtB.ktsgdw2c41
                    section.data(5).logicalSrcIdx = 62;
                    section.data(5).dtTransOffset = 513;

                    ;% rtB.mimixuazso
                    section.data(6).logicalSrcIdx = 63;
                    section.data(6).dtTransOffset = 514;

                    ;% rtB.jbdewy33ag
                    section.data(7).logicalSrcIdx = 64;
                    section.data(7).dtTransOffset = 515;

                    ;% rtB.jyujvnq2h1
                    section.data(8).logicalSrcIdx = 65;
                    section.data(8).dtTransOffset = 516;

                    ;% rtB.kmzeugzpgl
                    section.data(9).logicalSrcIdx = 66;
                    section.data(9).dtTransOffset = 517;

                    ;% rtB.lpstap4ud2
                    section.data(10).logicalSrcIdx = 67;
                    section.data(10).dtTransOffset = 518;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ktoqcjl1wu.n5nj1b05gf
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.elpvuejile.o5vabvlgjn
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.eoqlazxz1z.nf3awaueuw
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.c21bk5qnit.fsek3luzie
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtB.f2cxkdl2mb.etkpdfh3bw
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.f2cxkdl2mb.hogtdrsbl0
                    section.data(2).logicalSrcIdx = 73;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.f2cxkdl2mb.ayo4a0rtpb
                    section.data(3).logicalSrcIdx = 74;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hwhgormc0n.n5nj1b05gf
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.aelnqmel4f.jb2b5najpv
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.p2tfl52njg.fsek3luzie
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jdelhdqjdy.n5nj1b05gf
                    section.data(1).logicalSrcIdx = 78;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.dgjrsvf3r0.o5vabvlgjn
                    section.data(1).logicalSrcIdx = 79;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ch5un3rjrb.nf3awaueuw
                    section.data(1).logicalSrcIdx = 80;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.dwjvl3kmbe.fsek3luzie
                    section.data(1).logicalSrcIdx = 81;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(15) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtB.fisn2ndewy.etkpdfh3bw
                    section.data(1).logicalSrcIdx = 82;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.fisn2ndewy.hogtdrsbl0
                    section.data(2).logicalSrcIdx = 83;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.fisn2ndewy.ayo4a0rtpb
                    section.data(3).logicalSrcIdx = 84;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jsqwvo4npa.n5nj1b05gf
                    section.data(1).logicalSrcIdx = 85;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ixdl5r0pbu.jb2b5najpv
                    section.data(1).logicalSrcIdx = 86;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.c5fiym5p0p.fsek3luzie
                    section.data(1).logicalSrcIdx = 87;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(19) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtB.fvmfewdhwz.etkpdfh3bw
                    section.data(1).logicalSrcIdx = 88;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.fvmfewdhwz.hogtdrsbl0
                    section.data(2).logicalSrcIdx = 89;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.fvmfewdhwz.ayo4a0rtpb
                    section.data(3).logicalSrcIdx = 90;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(20) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtB.btyuoi1co3.a0dacr3vu5
                    section.data(1).logicalSrcIdx = 91;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.btyuoi1co3.dxojvg2mzp
                    section.data(2).logicalSrcIdx = 92;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.btyuoi1co3.ftth4nxmgz
                    section.data(3).logicalSrcIdx = 93;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.btyuoi1co3.d0v1fgzgtc
                    section.data(4).logicalSrcIdx = 94;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(21) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtB.ojl1qzu4tl.a0dacr3vu5
                    section.data(1).logicalSrcIdx = 95;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ojl1qzu4tl.dxojvg2mzp
                    section.data(2).logicalSrcIdx = 96;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ojl1qzu4tl.ftth4nxmgz
                    section.data(3).logicalSrcIdx = 97;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.ojl1qzu4tl.d0v1fgzgtc
                    section.data(4).logicalSrcIdx = 98;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(22) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 22;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hwcuhwqvaz
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bvsrcp4u0i
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 56;
            section.data(56)  = dumData; %prealloc

                    ;% rtDW.l30tmqcnmm
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.njuyqff5u5
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.iv3sxafqgs
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.dahp1m1tnz
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.egmxveifc2
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.nyak4kxjb0
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.jrcajuutzs
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.bto3rz2afq
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.l4a3zwvtji
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.ecriaizrd0
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.evnfi3oakh
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.jqu0hns3uo
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.ajtguqv0em
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.b42g2henkn
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.omefgf0cmg
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.eo5jyafoo5
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.leiplki144
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.g4ztp0b3on
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.oujf1dobik
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.pcv4wpi3ke
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.cbkkysibro
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.akkonxbiyb
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.e33if4mgu4
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.bkzeyuvdfi
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.jsetdp311j
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.ha3ig5blsd
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.og3gej3jwz
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.pv2wfqzep2
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.lakc2myacn
                    section.data(29).logicalSrcIdx = 30;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.ohxmf4okd1
                    section.data(30).logicalSrcIdx = 31;
                    section.data(30).dtTransOffset = 29;

                    ;% rtDW.jhaog44chc
                    section.data(31).logicalSrcIdx = 32;
                    section.data(31).dtTransOffset = 30;

                    ;% rtDW.ovo4hnxxnn
                    section.data(32).logicalSrcIdx = 33;
                    section.data(32).dtTransOffset = 31;

                    ;% rtDW.hpm14ul0f3
                    section.data(33).logicalSrcIdx = 34;
                    section.data(33).dtTransOffset = 32;

                    ;% rtDW.lkqen1tuni
                    section.data(34).logicalSrcIdx = 35;
                    section.data(34).dtTransOffset = 33;

                    ;% rtDW.ly5fhjl0pp
                    section.data(35).logicalSrcIdx = 36;
                    section.data(35).dtTransOffset = 34;

                    ;% rtDW.hiojixic5x
                    section.data(36).logicalSrcIdx = 37;
                    section.data(36).dtTransOffset = 35;

                    ;% rtDW.ps3do31sj3
                    section.data(37).logicalSrcIdx = 38;
                    section.data(37).dtTransOffset = 36;

                    ;% rtDW.mutemtyha2
                    section.data(38).logicalSrcIdx = 39;
                    section.data(38).dtTransOffset = 37;

                    ;% rtDW.dhidrj0fdd
                    section.data(39).logicalSrcIdx = 40;
                    section.data(39).dtTransOffset = 38;

                    ;% rtDW.frxhgtfui5
                    section.data(40).logicalSrcIdx = 41;
                    section.data(40).dtTransOffset = 39;

                    ;% rtDW.lrysnrlfpz
                    section.data(41).logicalSrcIdx = 42;
                    section.data(41).dtTransOffset = 40;

                    ;% rtDW.fl21cmk5gk
                    section.data(42).logicalSrcIdx = 43;
                    section.data(42).dtTransOffset = 41;

                    ;% rtDW.h4ow2pync3
                    section.data(43).logicalSrcIdx = 44;
                    section.data(43).dtTransOffset = 42;

                    ;% rtDW.juomdslsik
                    section.data(44).logicalSrcIdx = 45;
                    section.data(44).dtTransOffset = 43;

                    ;% rtDW.js0lpcxyrc
                    section.data(45).logicalSrcIdx = 46;
                    section.data(45).dtTransOffset = 44;

                    ;% rtDW.e0edvudjse
                    section.data(46).logicalSrcIdx = 47;
                    section.data(46).dtTransOffset = 45;

                    ;% rtDW.cmm1vcvsn0
                    section.data(47).logicalSrcIdx = 48;
                    section.data(47).dtTransOffset = 46;

                    ;% rtDW.e13leb2tmm
                    section.data(48).logicalSrcIdx = 49;
                    section.data(48).dtTransOffset = 47;

                    ;% rtDW.inoqsfj0bw
                    section.data(49).logicalSrcIdx = 50;
                    section.data(49).dtTransOffset = 48;

                    ;% rtDW.mkxeuv2wc4
                    section.data(50).logicalSrcIdx = 51;
                    section.data(50).dtTransOffset = 49;

                    ;% rtDW.dzzfid2chy
                    section.data(51).logicalSrcIdx = 52;
                    section.data(51).dtTransOffset = 50;

                    ;% rtDW.iz0phm120z
                    section.data(52).logicalSrcIdx = 53;
                    section.data(52).dtTransOffset = 51;

                    ;% rtDW.jlvcxty141
                    section.data(53).logicalSrcIdx = 54;
                    section.data(53).dtTransOffset = 52;

                    ;% rtDW.dfsexifu4j
                    section.data(54).logicalSrcIdx = 55;
                    section.data(54).dtTransOffset = 53;

                    ;% rtDW.csw4zgvz1w.modelTStart
                    section.data(55).logicalSrcIdx = 56;
                    section.data(55).dtTransOffset = 54;

                    ;% rtDW.lvn51ym2qo.modelTStart
                    section.data(56).logicalSrcIdx = 57;
                    section.data(56).dtTransOffset = 55;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 53;
            section.data(53)  = dumData; %prealloc

                    ;% rtDW.ijbiiwv2x1.LoggedData
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kveuuyfcbs.LoggedData
                    section.data(2).logicalSrcIdx = 59;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ciksye3m2u.LoggedData
                    section.data(3).logicalSrcIdx = 60;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jjh53xgtjl.LoggedData
                    section.data(4).logicalSrcIdx = 61;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.dnhlundi3t.LoggedData
                    section.data(5).logicalSrcIdx = 62;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.ekwl0yqhsl.LoggedData
                    section.data(6).logicalSrcIdx = 63;
                    section.data(6).dtTransOffset = 10;

                    ;% rtDW.gsignuaw3o.LoggedData
                    section.data(7).logicalSrcIdx = 64;
                    section.data(7).dtTransOffset = 12;

                    ;% rtDW.jejtfjwqmh.LoggedData
                    section.data(8).logicalSrcIdx = 65;
                    section.data(8).dtTransOffset = 14;

                    ;% rtDW.bupitfmcrk.LoggedData
                    section.data(9).logicalSrcIdx = 66;
                    section.data(9).dtTransOffset = 15;

                    ;% rtDW.gnziensnjw
                    section.data(10).logicalSrcIdx = 67;
                    section.data(10).dtTransOffset = 16;

                    ;% rtDW.flhcdf5cvg
                    section.data(11).logicalSrcIdx = 68;
                    section.data(11).dtTransOffset = 17;

                    ;% rtDW.mngvkp03ok.AQHandles
                    section.data(12).logicalSrcIdx = 69;
                    section.data(12).dtTransOffset = 18;

                    ;% rtDW.bpkyyz2duh.AQHandles
                    section.data(13).logicalSrcIdx = 70;
                    section.data(13).dtTransOffset = 19;

                    ;% rtDW.gwcnekeexx.AQHandles
                    section.data(14).logicalSrcIdx = 71;
                    section.data(14).dtTransOffset = 20;

                    ;% rtDW.jzk55zhlch.AQHandles
                    section.data(15).logicalSrcIdx = 72;
                    section.data(15).dtTransOffset = 21;

                    ;% rtDW.kao0trtwi5
                    section.data(16).logicalSrcIdx = 73;
                    section.data(16).dtTransOffset = 22;

                    ;% rtDW.okuzazai0s
                    section.data(17).logicalSrcIdx = 74;
                    section.data(17).dtTransOffset = 24;

                    ;% rtDW.pjgwumfyer
                    section.data(18).logicalSrcIdx = 75;
                    section.data(18).dtTransOffset = 26;

                    ;% rtDW.bmpybbr13l
                    section.data(19).logicalSrcIdx = 76;
                    section.data(19).dtTransOffset = 28;

                    ;% rtDW.omnw5jj5ix
                    section.data(20).logicalSrcIdx = 77;
                    section.data(20).dtTransOffset = 30;

                    ;% rtDW.lt2xcx2ium
                    section.data(21).logicalSrcIdx = 78;
                    section.data(21).dtTransOffset = 32;

                    ;% rtDW.pqulut3liz.TUbufferPtrs
                    section.data(22).logicalSrcIdx = 79;
                    section.data(22).dtTransOffset = 34;

                    ;% rtDW.l24xckmdwx.TUbufferPtrs
                    section.data(23).logicalSrcIdx = 80;
                    section.data(23).dtTransOffset = 36;

                    ;% rtDW.klrq4rnhqt.LoggedData
                    section.data(24).logicalSrcIdx = 81;
                    section.data(24).dtTransOffset = 38;

                    ;% rtDW.jg1r1xv5jr.LoggedData
                    section.data(25).logicalSrcIdx = 82;
                    section.data(25).dtTransOffset = 40;

                    ;% rtDW.kkqpashrw5.LoggedData
                    section.data(26).logicalSrcIdx = 83;
                    section.data(26).dtTransOffset = 41;

                    ;% rtDW.ddrfqg2rek.LoggedData
                    section.data(27).logicalSrcIdx = 84;
                    section.data(27).dtTransOffset = 42;

                    ;% rtDW.m3niq5rmug.LoggedData
                    section.data(28).logicalSrcIdx = 85;
                    section.data(28).dtTransOffset = 43;

                    ;% rtDW.iwjbducmiq.LoggedData
                    section.data(29).logicalSrcIdx = 86;
                    section.data(29).dtTransOffset = 45;

                    ;% rtDW.fdx4hqpd4d.LoggedData
                    section.data(30).logicalSrcIdx = 87;
                    section.data(30).dtTransOffset = 46;

                    ;% rtDW.onas52at42.LoggedData
                    section.data(31).logicalSrcIdx = 88;
                    section.data(31).dtTransOffset = 47;

                    ;% rtDW.ofdy3judrz.LoggedData
                    section.data(32).logicalSrcIdx = 89;
                    section.data(32).dtTransOffset = 48;

                    ;% rtDW.lozknuzswx.LoggedData
                    section.data(33).logicalSrcIdx = 90;
                    section.data(33).dtTransOffset = 49;

                    ;% rtDW.pxxwkrx4sy.LoggedData
                    section.data(34).logicalSrcIdx = 91;
                    section.data(34).dtTransOffset = 50;

                    ;% rtDW.ausvdyw0ag.LoggedData
                    section.data(35).logicalSrcIdx = 92;
                    section.data(35).dtTransOffset = 51;

                    ;% rtDW.e0uvnzzdpa.LoggedData
                    section.data(36).logicalSrcIdx = 93;
                    section.data(36).dtTransOffset = 52;

                    ;% rtDW.no1psf0mla.LoggedData
                    section.data(37).logicalSrcIdx = 94;
                    section.data(37).dtTransOffset = 54;

                    ;% rtDW.nuq2c3y2p2.LoggedData
                    section.data(38).logicalSrcIdx = 95;
                    section.data(38).dtTransOffset = 55;

                    ;% rtDW.jynhzjtulm.LoggedData
                    section.data(39).logicalSrcIdx = 96;
                    section.data(39).dtTransOffset = 56;

                    ;% rtDW.jmbpewghqz.LoggedData
                    section.data(40).logicalSrcIdx = 97;
                    section.data(40).dtTransOffset = 57;

                    ;% rtDW.m554pxlqkb.LoggedData
                    section.data(41).logicalSrcIdx = 98;
                    section.data(41).dtTransOffset = 58;

                    ;% rtDW.ngedooco0b.LoggedData
                    section.data(42).logicalSrcIdx = 99;
                    section.data(42).dtTransOffset = 59;

                    ;% rtDW.c2e0arl3lb.LoggedData
                    section.data(43).logicalSrcIdx = 100;
                    section.data(43).dtTransOffset = 60;

                    ;% rtDW.ow1b3l1s50.LoggedData
                    section.data(44).logicalSrcIdx = 101;
                    section.data(44).dtTransOffset = 62;

                    ;% rtDW.fjp5nmo3l5.LoggedData
                    section.data(45).logicalSrcIdx = 102;
                    section.data(45).dtTransOffset = 63;

                    ;% rtDW.lg2i4xshxy.LoggedData
                    section.data(46).logicalSrcIdx = 103;
                    section.data(46).dtTransOffset = 64;

                    ;% rtDW.lomz1vuozo.LoggedData
                    section.data(47).logicalSrcIdx = 104;
                    section.data(47).dtTransOffset = 65;

                    ;% rtDW.cz25bzuoih.LoggedData
                    section.data(48).logicalSrcIdx = 105;
                    section.data(48).dtTransOffset = 66;

                    ;% rtDW.omnabmm4il.LoggedData
                    section.data(49).logicalSrcIdx = 106;
                    section.data(49).dtTransOffset = 67;

                    ;% rtDW.eq3jhhlhby.LoggedData
                    section.data(50).logicalSrcIdx = 107;
                    section.data(50).dtTransOffset = 69;

                    ;% rtDW.hk0dpsz2d0.LoggedData
                    section.data(51).logicalSrcIdx = 108;
                    section.data(51).dtTransOffset = 70;

                    ;% rtDW.p3scgmzmwc.LoggedData
                    section.data(52).logicalSrcIdx = 109;
                    section.data(52).dtTransOffset = 71;

                    ;% rtDW.lagebt4c04.LoggedData
                    section.data(53).logicalSrcIdx = 110;
                    section.data(53).dtTransOffset = 72;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.jl0mnuibbh
                    section.data(1).logicalSrcIdx = 111;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.baqauvm4f0
                    section.data(2).logicalSrcIdx = 112;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.eam5on10cp
                    section.data(3).logicalSrcIdx = 113;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.f0ny4gmuvx
                    section.data(1).logicalSrcIdx = 114;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.l3xbscxi2g
                    section.data(2).logicalSrcIdx = 115;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.dcitng5a3n
                    section.data(3).logicalSrcIdx = 116;
                    section.data(3).dtTransOffset = 8;

                    ;% rtDW.jmc5mhc4s2
                    section.data(4).logicalSrcIdx = 117;
                    section.data(4).dtTransOffset = 12;

                    ;% rtDW.exvrlracxo
                    section.data(5).logicalSrcIdx = 118;
                    section.data(5).dtTransOffset = 16;

                    ;% rtDW.p22db1quvf
                    section.data(6).logicalSrcIdx = 119;
                    section.data(6).dtTransOffset = 20;

                    ;% rtDW.euinuevdxm
                    section.data(7).logicalSrcIdx = 120;
                    section.data(7).dtTransOffset = 24;

                    ;% rtDW.mr2aud2zdd.Tail
                    section.data(8).logicalSrcIdx = 121;
                    section.data(8).dtTransOffset = 28;

                    ;% rtDW.hmazbcxsfm.Tail
                    section.data(9).logicalSrcIdx = 122;
                    section.data(9).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.ag0g5gwgl3
                    section.data(1).logicalSrcIdx = 123;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bspqyhc1ui
                    section.data(2).logicalSrcIdx = 124;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% rtDW.gvaglrbdot
                    section.data(1).logicalSrcIdx = 125;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ottvoj0yqy
                    section.data(2).logicalSrcIdx = 126;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.dhockh40iz
                    section.data(3).logicalSrcIdx = 127;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.cosaluxqrd
                    section.data(4).logicalSrcIdx = 128;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ehbdlfy2zi
                    section.data(5).logicalSrcIdx = 129;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.hkguujkgog
                    section.data(6).logicalSrcIdx = 130;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.nkmva5gdkf
                    section.data(7).logicalSrcIdx = 131;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.k043rv4keo
                    section.data(8).logicalSrcIdx = 132;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.mmap3xsiti
                    section.data(9).logicalSrcIdx = 133;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.nmtkuzrjds
                    section.data(10).logicalSrcIdx = 134;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.nbwsx1apcl
                    section.data(11).logicalSrcIdx = 135;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.gmsb3q2zlj
                    section.data(12).logicalSrcIdx = 136;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.iaghp1202d
                    section.data(13).logicalSrcIdx = 137;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.jpzpmlt0aw
                    section.data(14).logicalSrcIdx = 138;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2532647534;
    targMap.checksum1 = 717479846;
    targMap.checksum2 = 1968865415;
    targMap.checksum3 = 3579019364;

