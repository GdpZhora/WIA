xof 0302txt 0032
Header {
 1;
 0;
 1;
}
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}
template FloatKeys {
 <10DD46A9-775B-11cf-8F52-0040333594A3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <F406B180-7B3B-11cf-8F52-0040333594A3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10DD46A8-775B-11cf-8F52-0040333594A3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template AnimationOptions {
 <E2BF56C0-840F-11cf-8F52-0040333594A3>
 DWORD openclosed;
 DWORD positionquality;
}

template Animation {
 <3D82AB4F-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template AnimationSet {
 <3D82AB50-62DA-11cf-AB39-0020AF71E433>
 [Animation]
}
Frame Frm-Box13 {
   FrameTransformMatrix {
1.000000,0.000000,0.000000,0.000000,
0.000000,1.000000,0.000000,0.000000,
0.000000,0.000000,1.000000,0.000000,
15.707760,15.707764,-1.380570,1.000000;;
 }
Mesh Box13 {
 84;
-45.440262;-21.281647;0.987214;,
-56.505741;-20.267822;1.027962;,
-56.505741;-25.090210;2.761139;,
-46.915485;-25.971802;2.920680;,
18.142433;-33.039948;0.987214;,
20.267830;-56.505737;1.027962;,
25.090225;-56.505737;2.761139;,
22.832588;-31.564697;2.920681;,
-21.281673;-45.440247;0.987214;,
-20.267853;-56.505737;1.027962;,
-14.924648;-56.505737;0.000001;,
-16.084980;-43.805725;-0.159541;,
-11.134594;-56.505737;0.797860;,
-12.398861;-42.646301;0.730520;,
-6.680759;-56.505737;1.598576;,
-8.067162;-41.283813;1.623769;,
-2.226929;-56.505707;2.079854;,
-3.735466;-39.921326;2.160664;,
2.226906;-56.505707;2.079854;,
0.596230;-38.558838;2.160664;,
6.680740;-56.505737;1.598576;,
4.927929;-37.196381;1.623769;,
11.134567;-56.505737;0.797860;,
9.259644;-35.833893;0.730520;,
14.924629;-56.505737;0.000001;,
12.945755;-34.674500;-0.159541;,
-36.385117;-24.305817;0.962765;,
-39.066963;-28.595123;3.016406;,
-29.340302;-29.340302;0.954615;,
-32.960182;-32.960175;3.048315;,
-24.305824;-36.385101;0.962765;,
-28.595133;-39.066956;3.016406;,
-25.971821;-46.915497;2.920681;,
-25.090244;-56.505737;2.761139;,
11.748962;-13.842224;0.962765;,
16.038277;-11.160370;3.016406;,
1.087414;1.087433;0.954615;,
4.707298;4.707306;3.048315;,
-13.842232;11.748962;0.962764;,
-11.160374;16.038269;3.016406;,
-33.039940;18.142441;0.987213;,
-31.564714;22.832596;2.920680;,
-56.505737;20.267838;1.027962;,
-56.505733;25.090225;2.761139;,
-19.553261;-33.413605;-0.255267;,
-25.329475;-25.329468;-0.287175;,
-33.413628;-19.553253;-0.255267;,
-43.805717;-16.084961;-0.159542;,
-56.505745;-14.924622;0.000000;,
-16.182163;-31.305878;0.690116;,
-22.484509;-22.484497;0.676648;,
-31.305887;-16.182159;0.690116;,
-42.646294;-12.398865;0.730520;,
-56.505741;-11.134583;0.797859;,
-12.220673;-28.828979;1.638885;,
-19.141285;-19.141266;1.643923;,
-28.828995;-12.220673;1.638885;,
-41.283813;-8.067169;1.623769;,
-56.505726;-6.680756;1.598575;,
-8.259178;-26.352112;2.209151;,
-15.798058;-15.798065;2.225313;,
-26.352108;-8.259155;2.209151;,
-39.921326;-3.735443;2.160664;,
-56.505714;-2.226898;2.079853;,
-4.297680;-23.875214;2.209151;,
-12.454830;-12.454834;2.225313;,
-23.875221;-4.297668;2.209151;,
-38.558846;0.596252;2.160664;,
-56.505714;2.226929;2.079853;,
-0.336185;-21.398315;1.638885;,
-9.111607;-9.111603;1.643923;,
-21.398338;-0.336182;1.638885;,
-37.196373;4.927948;1.623769;,
-56.505722;6.680756;1.598575;,
3.625320;-18.921448;0.690116;,
-5.768368;-5.768372;0.676648;,
-18.921452;3.625305;0.690116;,
-35.833900;9.259644;0.730520;,
-56.505737;11.134583;0.797859;,
6.996410;-16.813690;-0.255267;,
-2.923412;-2.923401;-0.287175;,
-16.813717;6.996429;-0.255267;,
-34.674488;12.945770;-0.159542;,
-56.505745;14.924622;0.000000;;

 132;
3;0,1,2;,
3;2,3,0;,
3;4,5,6;,
3;6,7,4;,
3;8,9,10;,
3;10,11,8;,
3;11,10,12;,
3;12,13,11;,
3;13,12,14;,
3;14,15,13;,
3;15,14,16;,
3;16,17,15;,
3;17,16,18;,
3;18,19,17;,
3;19,18,20;,
3;20,21,19;,
3;21,20,22;,
3;22,23,21;,
3;23,22,24;,
3;24,25,23;,
3;25,24,5;,
3;5,4,25;,
3;26,0,3;,
3;3,27,26;,
3;28,26,27;,
3;27,29,28;,
3;30,28,29;,
3;29,31,30;,
3;8,30,31;,
3;31,32,8;,
3;9,8,32;,
3;32,33,9;,
3;34,4,7;,
3;7,35,34;,
3;36,34,35;,
3;35,37,36;,
3;38,36,37;,
3;37,39,38;,
3;40,38,39;,
3;39,41,40;,
3;42,40,41;,
3;41,43,42;,
3;30,8,11;,
3;11,44,30;,
3;28,30,44;,
3;44,45,28;,
3;26,28,45;,
3;45,46,26;,
3;0,26,46;,
3;46,47,0;,
3;1,0,47;,
3;47,48,1;,
3;44,11,13;,
3;13,49,44;,
3;45,44,49;,
3;49,50,45;,
3;46,45,50;,
3;50,51,46;,
3;47,46,51;,
3;51,52,47;,
3;48,47,52;,
3;52,53,48;,
3;49,13,15;,
3;15,54,49;,
3;50,49,54;,
3;54,55,50;,
3;51,50,55;,
3;55,56,51;,
3;52,51,56;,
3;56,57,52;,
3;53,52,57;,
3;57,58,53;,
3;54,15,17;,
3;17,59,54;,
3;55,54,59;,
3;59,60,55;,
3;56,55,60;,
3;60,61,56;,
3;57,56,61;,
3;61,62,57;,
3;58,57,62;,
3;62,63,58;,
3;59,17,19;,
3;19,64,59;,
3;60,59,64;,
3;64,65,60;,
3;61,60,65;,
3;65,66,61;,
3;62,61,66;,
3;66,67,62;,
3;63,62,67;,
3;67,68,63;,
3;64,19,21;,
3;21,69,64;,
3;65,64,69;,
3;69,70,65;,
3;66,65,70;,
3;70,71,66;,
3;67,66,71;,
3;71,72,67;,
3;68,67,72;,
3;72,73,68;,
3;69,21,23;,
3;23,74,69;,
3;70,69,74;,
3;74,75,70;,
3;71,70,75;,
3;75,76,71;,
3;72,71,76;,
3;76,77,72;,
3;73,72,77;,
3;77,78,73;,
3;74,23,25;,
3;25,79,74;,
3;75,74,79;,
3;79,80,75;,
3;76,75,80;,
3;80,81,76;,
3;77,76,81;,
3;81,82,77;,
3;78,77,82;,
3;82,83,78;,
3;79,25,4;,
3;4,34,79;,
3;80,79,34;,
3;34,36,80;,
3;81,80,36;,
3;36,38,81;,
3;82,81,38;,
3;38,40,82;,
3;83,82,40;,
3;40,42,83;;
MeshMaterialList {
 1;
 132;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
Material {
 0.752941;0.752941;0.752941;1.000000;;
8.000000;
 0.752941;0.752941;0.752941;;
 0.023529;0.023529;0.023529;;
 }
}

 MeshNormals {
 84;
0.056745;0.278963;0.958624;,
0.028979;0.245741;0.968902;,
0.026794;0.357045;0.933703;,
0.083453;0.364816;0.927332;,
-0.279436;-0.054964;0.958590;,
-0.246332;-0.018805;0.969003;,
-0.354196;-0.034223;0.934545;,
-0.360734;-0.093211;0.927999;,
0.280446;0.064792;0.957681;,
0.300318;0.024666;0.953520;,
0.064157;0.015453;0.997820;,
-0.008240;0.015287;0.999849;,
-0.204313;-0.011378;0.978839;,
-0.205040;-0.040065;0.977933;,
-0.160255;-0.014099;0.986975;,
-0.151855;-0.034760;0.987791;,
-0.075304;-0.010645;0.997104;,
-0.057304;-0.018142;0.998192;,
0.036316;-0.001324;0.999339;,
0.057413;0.006461;0.998330;,
0.134858;0.009892;0.990816;,
0.151280;0.029731;0.988044;,
0.192839;0.019194;0.981043;,
0.202821;0.045058;0.978179;,
0.082684;0.013435;0.996485;,
0.011167;0.015784;0.999813;,
0.129769;0.263892;0.955783;,
0.184431;0.330976;0.925440;,
0.205004;0.213059;0.955290;,
0.280357;0.251611;0.926332;,
0.260175;0.139320;0.955457;,
0.341588;0.148773;0.928000;,
0.353412;0.052905;0.933971;,
0.338181;0.015433;0.940955;,
-0.263903;-0.129607;0.955802;,
-0.327455;-0.189485;0.925672;,
-0.211767;-0.206171;0.955326;,
-0.251480;-0.280964;0.926184;,
-0.136537;-0.261776;0.955422;,
-0.153753;-0.339829;0.927834;,
-0.060941;-0.281516;0.957619;,
-0.062825;-0.352423;0.933730;,
-0.028139;-0.300773;0.953281;,
-0.036611;-0.337995;0.940436;,
-0.014335;0.010580;0.999841;,
-0.015567;0.002162;0.999876;,
-0.011187;-0.007438;0.999910;,
-0.003243;-0.014612;0.999888;,
0.002231;-0.084661;0.996407;,
-0.191906;-0.096600;0.976648;,
-0.151213;-0.153307;0.976541;,
-0.094170;-0.192956;0.976678;,
-0.038047;-0.204833;0.978057;,
-0.015025;-0.193625;0.980961;,
-0.141355;-0.075149;0.987102;,
-0.111613;-0.115220;0.987050;,
-0.070813;-0.142914;0.987199;,
-0.031099;-0.150910;0.988058;,
-0.014957;-0.134551;0.990794;,
-0.051985;-0.032241;0.998127;,
-0.040578;-0.045464;0.998142;,
-0.026249;-0.053889;0.998202;,
-0.013046;-0.055539;0.998371;,
-0.007962;-0.035357;0.999343;,
0.055707;0.022998;0.998182;,
0.045142;0.040646;0.998153;,
0.028573;0.054059;0.998129;,
0.011227;0.059274;0.998179;,
0.003497;0.076250;0.997083;,
0.143084;0.070437;0.987201;,
0.114658;0.112098;0.987060;,
0.073659;0.142217;0.987091;,
0.032509;0.152496;0.987769;,
0.014779;0.160545;0.986918;,
0.190651;0.098168;0.976737;,
0.152735;0.151989;0.976510;,
0.099165;0.190490;0.976668;,
0.045942;0.203385;0.978020;,
0.022965;0.203517;0.978802;,
0.003942;0.017597;0.999837;,
-0.001814;0.015778;0.999874;,
-0.004027;0.010730;0.999934;,
-0.002619;0.004723;0.999985;,
-0.000561;-0.066180;0.997808;;

 132;
3;0,1,2;,
3;2,3,0;,
3;4,5,6;,
3;6,7,4;,
3;8,9,10;,
3;10,11,8;,
3;11,10,12;,
3;12,13,11;,
3;13,12,14;,
3;14,15,13;,
3;15,14,16;,
3;16,17,15;,
3;17,16,18;,
3;18,19,17;,
3;19,18,20;,
3;20,21,19;,
3;21,20,22;,
3;22,23,21;,
3;23,22,24;,
3;24,25,23;,
3;25,24,5;,
3;5,4,25;,
3;26,0,3;,
3;3,27,26;,
3;28,26,27;,
3;27,29,28;,
3;30,28,29;,
3;29,31,30;,
3;8,30,31;,
3;31,32,8;,
3;9,8,32;,
3;32,33,9;,
3;34,4,7;,
3;7,35,34;,
3;36,34,35;,
3;35,37,36;,
3;38,36,37;,
3;37,39,38;,
3;40,38,39;,
3;39,41,40;,
3;42,40,41;,
3;41,43,42;,
3;30,8,11;,
3;11,44,30;,
3;28,30,44;,
3;44,45,28;,
3;26,28,45;,
3;45,46,26;,
3;0,26,46;,
3;46,47,0;,
3;1,0,47;,
3;47,48,1;,
3;44,11,13;,
3;13,49,44;,
3;45,44,49;,
3;49,50,45;,
3;46,45,50;,
3;50,51,46;,
3;47,46,51;,
3;51,52,47;,
3;48,47,52;,
3;52,53,48;,
3;49,13,15;,
3;15,54,49;,
3;50,49,54;,
3;54,55,50;,
3;51,50,55;,
3;55,56,51;,
3;52,51,56;,
3;56,57,52;,
3;53,52,57;,
3;57,58,53;,
3;54,15,17;,
3;17,59,54;,
3;55,54,59;,
3;59,60,55;,
3;56,55,60;,
3;60,61,56;,
3;57,56,61;,
3;61,62,57;,
3;58,57,62;,
3;62,63,58;,
3;59,17,19;,
3;19,64,59;,
3;60,59,64;,
3;64,65,60;,
3;61,60,65;,
3;65,66,61;,
3;62,61,66;,
3;66,67,62;,
3;63,62,67;,
3;67,68,63;,
3;64,19,21;,
3;21,69,64;,
3;65,64,69;,
3;69,70,65;,
3;66,65,70;,
3;70,71,66;,
3;67,66,71;,
3;71,72,67;,
3;68,67,72;,
3;72,73,68;,
3;69,21,23;,
3;23,74,69;,
3;70,69,74;,
3;74,75,70;,
3;71,70,75;,
3;75,76,71;,
3;72,71,76;,
3;76,77,72;,
3;73,72,77;,
3;77,78,73;,
3;74,23,25;,
3;25,79,74;,
3;75,74,79;,
3;79,80,75;,
3;76,75,80;,
3;80,81,76;,
3;77,76,81;,
3;81,82,77;,
3;78,77,82;,
3;82,83,78;,
3;79,25,4;,
3;4,34,79;,
3;80,79,34;,
3;34,36,80;,
3;81,80,36;,
3;36,38,81;,
3;82,81,38;,
3;38,40,82;,
3;83,82,40;,
3;40,42,83;;
 }
MeshTextureCoords {
 84;
0.166667;0.717808;,
0.000000;0.717808;,
0.000000;1.000000;,
0.166667;1.000000;,
0.833333;0.282192;,
1.000000;0.282192;,
1.000000;0.000000;,
0.833333;0.000000;,
0.833333;0.717808;,
1.000000;0.717808;,
1.000000;0.669406;,
0.833333;0.669406;,
1.000000;0.621005;,
0.833333;0.621005;,
1.000000;0.572603;,
0.833333;0.572603;,
1.000000;0.524201;,
0.833333;0.524201;,
1.000000;0.475799;,
0.833333;0.475799;,
1.000000;0.427397;,
0.833333;0.427397;,
1.000000;0.378995;,
0.833333;0.378995;,
1.000000;0.330594;,
0.833333;0.330594;,
0.333333;0.717808;,
0.333333;1.000000;,
0.500000;0.717808;,
0.500000;1.000000;,
0.666667;0.717808;,
0.666667;1.000000;,
0.833333;1.000000;,
1.000000;1.000000;,
0.666667;0.282192;,
0.666667;0.000000;,
0.500000;0.282192;,
0.500000;0.000000;,
0.333333;0.282192;,
0.333333;0.000000;,
0.166667;0.282192;,
0.166667;0.000000;,
0.000000;0.282192;,
0.000000;0.000000;,
0.666667;0.669406;,
0.500000;0.669406;,
0.333333;0.669406;,
0.166667;0.669406;,
0.000000;0.669406;,
0.666667;0.621005;,
0.500000;0.621005;,
0.333333;0.621005;,
0.166667;0.621005;,
0.000000;0.621005;,
0.666667;0.572603;,
0.500000;0.572603;,
0.333333;0.572603;,
0.166667;0.572603;,
0.000000;0.572603;,
0.666667;0.524201;,
0.500000;0.524201;,
0.333333;0.524201;,
0.166667;0.524201;,
0.000000;0.524201;,
0.666667;0.475799;,
0.500000;0.475799;,
0.333333;0.475799;,
0.166667;0.475799;,
0.000000;0.475799;,
0.666667;0.427397;,
0.500000;0.427397;,
0.333333;0.427397;,
0.166667;0.427397;,
0.000000;0.427397;,
0.666667;0.378995;,
0.500000;0.378995;,
0.333333;0.378995;,
0.166667;0.378995;,
0.000000;0.378995;,
0.666667;0.330594;,
0.500000;0.330594;,
0.333333;0.330594;,
0.166667;0.330594;,
0.000000;0.330594;;
}
}
 }