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
Frame Frm-Box38 {
   FrameTransformMatrix {
1.000000,0.000000,0.000000,0.000000,
0.000000,1.000000,0.000000,0.000000,
0.000000,0.000000,1.000000,0.000000,
0.000001,0.000000,-12.533337,1.000000;;
 }
Mesh Box38 {
 160;
56.505737;-25.090229;2.761139;,
56.505737;-20.267838;1.027962;,
-56.505737;-20.267832;1.027962;,
-56.505737;-25.090221;2.761139;,
56.505737;25.090221;2.761139;,
-56.505737;25.090229;2.761139;,
-56.505737;20.267838;1.027962;,
56.505737;20.267832;1.027962;,
-56.505745;-14.924631;0.000000;,
56.505745;-14.924631;0.000000;,
-56.505737;-11.134581;0.797859;,
56.505737;-11.134579;0.797859;,
-56.505726;-6.680747;1.598576;,
56.505726;-6.680747;1.598576;,
-56.505718;-2.226914;2.079853;,
56.505718;-2.226916;2.079853;,
-56.505718;2.226917;2.079853;,
56.505718;2.226916;2.079853;,
-56.505726;6.680747;1.598576;,
56.505726;6.680748;1.598576;,
-56.505737;11.134579;0.797859;,
56.505737;11.134581;0.797859;,
-56.505745;14.924631;0.000000;,
56.505745;14.924631;0.000000;,
10.323611;19.997210;16.577091;,
10.323611;21.161659;23.353790;,
10.323610;15.053060;24.251160;,
10.323610;14.219339;17.425877;,
10.323609;8.908067;24.850590;,
10.323609;8.407045;17.992851;,
10.323607;2.741203;25.150661;,
10.323608;2.574063;18.276672;,
10.323606;-3.432957;25.150661;,
10.323607;-3.265819;18.276680;,
10.323606;-9.599822;24.850590;,
10.323606;-9.098801;17.992851;,
10.323605;-15.744816;24.251163;,
10.323605;-14.911095;17.425877;,
10.323604;-21.853416;23.353794;,
10.323604;-20.688965;16.577091;,
10.021087;19.997210;16.577091;,
10.021086;14.219339;17.425877;,
10.021086;15.053060;24.251160;,
10.021087;21.161659;23.353790;,
10.021085;8.407045;17.992851;,
10.021085;8.908067;24.850590;,
10.021084;2.574063;18.276672;,
10.021084;2.741203;25.150661;,
10.021083;-3.265819;18.276680;,
10.021082;-3.432957;25.150661;,
10.021082;-9.098801;17.992851;,
10.021081;-9.599822;24.850590;,
10.021081;-14.911095;17.425877;,
10.021080;-15.744816;24.251163;,
10.021080;-20.688965;16.577091;,
10.021079;-21.853416;23.353794;,
10.323611;19.997210;16.577091;,
10.323610;14.219339;17.425877;,
10.021086;14.219339;17.425877;,
10.021087;19.997210;16.577091;,
10.323610;14.219339;17.425877;,
10.323609;8.407045;17.992851;,
10.021085;8.407045;17.992851;,
10.021086;14.219339;17.425877;,
10.323609;8.407045;17.992851;,
10.323608;2.574063;18.276672;,
10.021084;2.574063;18.276672;,
10.021085;8.407045;17.992851;,
10.323608;2.574063;18.276672;,
10.323607;-3.265819;18.276680;,
10.021083;-3.265819;18.276680;,
10.021084;2.574063;18.276672;,
10.323607;-3.265819;18.276680;,
10.323606;-9.098801;17.992851;,
10.021082;-9.098801;17.992851;,
10.021083;-3.265819;18.276680;,
10.323606;-9.098801;17.992851;,
10.323605;-14.911095;17.425877;,
10.021081;-14.911095;17.425877;,
10.021082;-9.098801;17.992851;,
10.323605;-14.911095;17.425877;,
10.323604;-20.688965;16.577091;,
10.021080;-20.688965;16.577091;,
10.021081;-14.911095;17.425877;,
10.323604;-20.688965;16.577091;,
10.323604;-21.853416;23.353794;,
10.021079;-21.853416;23.353794;,
10.021080;-20.688965;16.577091;,
10.323604;-21.853416;23.353794;,
10.323605;-15.744816;24.251163;,
10.021080;-15.744816;24.251163;,
10.021079;-21.853416;23.353794;,
10.323605;-15.744816;24.251163;,
10.323606;-9.599822;24.850590;,
10.021081;-9.599822;24.850590;,
10.021080;-15.744816;24.251163;,
10.323606;-9.599822;24.850590;,
10.323606;-3.432957;25.150661;,
10.021082;-3.432957;25.150661;,
10.021081;-9.599822;24.850590;,
10.323606;-3.432957;25.150661;,
10.323607;2.741203;25.150661;,
10.021084;2.741203;25.150661;,
10.021082;-3.432957;25.150661;,
10.323607;2.741203;25.150661;,
10.323609;8.908067;24.850590;,
10.021085;8.908067;24.850590;,
10.021084;2.741203;25.150661;,
10.323609;8.908067;24.850590;,
10.323610;15.053060;24.251160;,
10.021086;15.053060;24.251160;,
10.021085;8.908067;24.850590;,
10.323610;15.053060;24.251160;,
10.323611;21.161659;23.353790;,
10.021087;21.161659;23.353790;,
10.021086;15.053060;24.251160;,
10.323611;21.161659;23.353790;,
10.323611;19.997210;16.577091;,
10.021087;19.997210;16.577091;,
10.021087;21.161659;23.353790;,
9.815865;-22.281651;24.265652;,
10.514324;-22.281651;24.265652;,
10.514324;-21.593801;24.386940;,
9.815865;-21.593801;24.386940;,
9.815865;-17.988153;-0.083988;,
10.514324;-17.988153;-0.083988;,
10.514324;-22.281651;24.265652;,
9.815865;-22.281651;24.265652;,
10.514324;-17.988153;-0.083988;,
10.514324;-17.300303;0.037300;,
10.514324;-21.593801;24.386940;,
10.514324;-22.281651;24.265652;,
10.514324;-17.300303;0.037300;,
9.815865;-17.300303;0.037300;,
9.815865;-21.593801;24.386940;,
10.514324;-21.593801;24.386940;,
9.815865;-17.300303;0.037300;,
9.815865;-17.988153;-0.083988;,
9.815865;-22.281651;24.265652;,
9.815865;-21.593801;24.386940;,
9.815865;21.805634;24.265652;,
9.815865;21.117788;24.386940;,
10.514324;21.117788;24.386940;,
10.514324;21.805634;24.265652;,
9.815865;17.512140;-0.083984;,
9.815865;21.805634;24.265652;,
10.514324;21.805634;24.265652;,
10.514324;17.512140;-0.083984;,
10.514324;17.512140;-0.083984;,
10.514324;21.805634;24.265652;,
10.514324;21.117788;24.386940;,
10.514324;16.824291;0.037304;,
10.514324;16.824291;0.037304;,
10.514324;21.117788;24.386940;,
9.815865;21.117788;24.386940;,
9.815865;16.824291;0.037304;,
9.815865;16.824291;0.037304;,
9.815865;21.117788;24.386940;,
9.815865;21.805634;24.265652;,
9.815865;17.512140;-0.083984;;

 102;
3;0,1,2;,
3;2,3,0;,
3;4,5,6;,
3;6,7,4;,
3;8,2,1;,
3;1,9,8;,
3;10,8,9;,
3;9,11,10;,
3;12,10,11;,
3;11,13,12;,
3;14,12,13;,
3;13,15,14;,
3;16,14,15;,
3;15,17,16;,
3;18,16,17;,
3;17,19,18;,
3;20,18,19;,
3;19,21,20;,
3;22,20,21;,
3;21,23,22;,
3;6,22,23;,
3;23,7,6;,
3;24,25,26;,
3;26,27,24;,
3;27,26,28;,
3;28,29,27;,
3;29,28,30;,
3;30,31,29;,
3;31,30,32;,
3;32,33,31;,
3;33,32,34;,
3;34,35,33;,
3;35,34,36;,
3;36,37,35;,
3;37,36,38;,
3;38,39,37;,
3;40,41,42;,
3;42,43,40;,
3;41,44,45;,
3;45,42,41;,
3;44,46,47;,
3;47,45,44;,
3;46,48,49;,
3;49,47,46;,
3;48,50,51;,
3;51,49,48;,
3;50,52,53;,
3;53,51,50;,
3;52,54,55;,
3;55,53,52;,
3;56,57,58;,
3;58,59,56;,
3;60,61,62;,
3;62,63,60;,
3;64,65,66;,
3;66,67,64;,
3;68,69,70;,
3;70,71,68;,
3;72,73,74;,
3;74,75,72;,
3;76,77,78;,
3;78,79,76;,
3;80,81,82;,
3;82,83,80;,
3;84,85,86;,
3;86,87,84;,
3;88,89,90;,
3;90,91,88;,
3;92,93,94;,
3;94,95,92;,
3;96,97,98;,
3;98,99,96;,
3;100,101,102;,
3;102,103,100;,
3;104,105,106;,
3;106,107,104;,
3;108,109,110;,
3;110,111,108;,
3;112,113,114;,
3;114,115,112;,
3;116,117,118;,
3;118,119,116;,
3;120,121,122;,
3;122,123,120;,
3;124,125,126;,
3;126,127,124;,
3;128,129,130;,
3;130,131,128;,
3;132,133,134;,
3;134,135,132;,
3;136,137,138;,
3;138,139,136;,
3;140,141,142;,
3;142,143,140;,
3;144,145,146;,
3;146,147,144;,
3;148,149,150;,
3;150,151,148;,
3;152,153,154;,
3;154,155,152;,
3;156,157,158;,
3;158,159,156;;
MeshMaterialList {
 1;
 102;
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
 160;
0.000000;0.338221;0.941067;,
0.000000;0.239327;0.970939;,
0.000000;0.289226;0.957261;,
0.000000;0.338221;0.941067;,
0.000000;-0.338221;0.941067;,
0.000000;-0.338221;0.941067;,
0.000000;-0.264365;0.964423;,
0.000000;-0.264365;0.964423;,
0.000000;0.058301;0.998299;,
0.000000;-0.075682;0.997132;,
0.000000;-0.196333;0.980537;,
0.000000;-0.186648;0.982427;,
0.000000;-0.153859;0.988093;,
0.000000;-0.130676;0.991425;,
0.000000;-0.071715;0.997425;,
0.000000;-0.035857;0.999357;,
0.000000;0.035857;0.999357;,
0.000000;0.071715;0.997425;,
0.000000;0.130676;0.991425;,
0.000000;0.153859;0.988093;,
0.000000;0.186648;0.982427;,
0.000000;0.196333;0.980537;,
0.000000;0.075682;0.997132;,
0.000000;-0.058301;0.998299;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
0.000000;-0.145343;-0.989381;,
0.000000;-0.145343;-0.989381;,
0.000000;-0.145343;-0.989381;,
0.000000;-0.145343;-0.989381;,
0.000000;-0.097087;-0.995276;,
0.000000;-0.097087;-0.995276;,
0.000000;-0.097087;-0.995276;,
0.000000;-0.097087;-0.995276;,
0.000000;-0.048600;-0.998818;,
0.000000;-0.048600;-0.998818;,
0.000000;-0.048600;-0.998818;,
0.000000;-0.048600;-0.998818;,
0.000000;-0.000001;-1.000000;,
0.000000;-0.000001;-1.000000;,
0.000000;-0.000001;-1.000000;,
0.000000;-0.000001;-1.000000;,
0.000000;0.048602;-0.998818;,
0.000000;0.048602;-0.998818;,
0.000000;0.048602;-0.998818;,
0.000000;0.048602;-0.998818;,
0.000000;0.097087;-0.995276;,
0.000000;0.097087;-0.995276;,
0.000000;0.097087;-0.995276;,
0.000000;0.097087;-0.995276;,
0.000000;0.145343;-0.989381;,
0.000000;0.145343;-0.989381;,
0.000000;0.145343;-0.989381;,
0.000000;0.145343;-0.989381;,
0.000000;-0.985556;-0.169350;,
0.000000;-0.985556;-0.169350;,
0.000000;-0.985556;-0.169350;,
0.000000;-0.985556;-0.169350;,
0.000000;-0.145343;0.989381;,
0.000000;-0.145343;0.989381;,
0.000000;-0.145343;0.989381;,
0.000000;-0.145343;0.989381;,
0.000000;-0.097086;0.995276;,
0.000000;-0.097086;0.995276;,
0.000000;-0.097086;0.995276;,
0.000000;-0.097086;0.995276;,
0.000000;-0.048601;0.998818;,
0.000000;-0.048601;0.998818;,
0.000000;-0.048601;0.998818;,
0.000000;-0.048601;0.998818;,
0.000000;0.000000;1.000000;,
0.000000;0.000000;1.000000;,
0.000000;0.000000;1.000000;,
0.000000;0.000000;1.000000;,
0.000000;0.048601;0.998818;,
0.000000;0.048601;0.998818;,
0.000000;0.048601;0.998818;,
0.000000;0.048601;0.998818;,
0.000000;0.097087;0.995276;,
0.000000;0.097087;0.995276;,
0.000000;0.097087;0.995276;,
0.000000;0.097087;0.995276;,
0.000000;0.145343;0.989381;,
0.000000;0.145343;0.989381;,
0.000000;0.145343;0.989381;,
0.000000;0.145343;0.989381;,
0.000000;0.985556;-0.169349;,
0.000000;0.985556;-0.169349;,
0.000000;0.985556;-0.169349;,
0.000000;0.985556;-0.169349;,
0.000000;-0.173651;0.984807;,
0.000000;-0.173651;0.984807;,
0.000000;-0.173651;0.984807;,
0.000000;-0.173651;0.984807;,
0.000000;-0.984808;-0.173648;,
0.000000;-0.984808;-0.173648;,
0.000000;-0.984808;-0.173648;,
0.000000;-0.984808;-0.173648;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
0.000000;0.984808;0.173648;,
0.000000;0.984808;0.173648;,
0.000000;0.984808;0.173648;,
0.000000;0.984808;0.173648;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
0.000000;0.173652;0.984807;,
0.000000;0.173652;0.984807;,
0.000000;0.173652;0.984807;,
0.000000;0.173652;0.984807;,
0.000000;0.984808;-0.173648;,
0.000000;0.984808;-0.173648;,
0.000000;0.984808;-0.173648;,
0.000000;0.984808;-0.173648;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
1.000000;0.000000;0.000000;,
0.000000;-0.984808;0.173648;,
0.000000;-0.984808;0.173648;,
0.000000;-0.984808;0.173648;,
0.000000;-0.984808;0.173648;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;,
-1.000000;0.000000;0.000000;;

 102;
3;0,1,2;,
3;2,3,0;,
3;4,5,6;,
3;6,7,4;,
3;8,2,1;,
3;1,9,8;,
3;10,8,9;,
3;9,11,10;,
3;12,10,11;,
3;11,13,12;,
3;14,12,13;,
3;13,15,14;,
3;16,14,15;,
3;15,17,16;,
3;18,16,17;,
3;17,19,18;,
3;20,18,19;,
3;19,21,20;,
3;22,20,21;,
3;21,23,22;,
3;6,22,23;,
3;23,7,6;,
3;24,25,26;,
3;26,27,24;,
3;27,26,28;,
3;28,29,27;,
3;29,28,30;,
3;30,31,29;,
3;31,30,32;,
3;32,33,31;,
3;33,32,34;,
3;34,35,33;,
3;35,34,36;,
3;36,37,35;,
3;37,36,38;,
3;38,39,37;,
3;40,41,42;,
3;42,43,40;,
3;41,44,45;,
3;45,42,41;,
3;44,46,47;,
3;47,45,44;,
3;46,48,49;,
3;49,47,46;,
3;48,50,51;,
3;51,49,48;,
3;50,52,53;,
3;53,51,50;,
3;52,54,55;,
3;55,53,52;,
3;56,57,58;,
3;58,59,56;,
3;60,61,62;,
3;62,63,60;,
3;64,65,66;,
3;66,67,64;,
3;68,69,70;,
3;70,71,68;,
3;72,73,74;,
3;74,75,72;,
3;76,77,78;,
3;78,79,76;,
3;80,81,82;,
3;82,83,80;,
3;84,85,86;,
3;86,87,84;,
3;88,89,90;,
3;90,91,88;,
3;92,93,94;,
3;94,95,92;,
3;96,97,98;,
3;98,99,96;,
3;100,101,102;,
3;102,103,100;,
3;104,105,106;,
3;106,107,104;,
3;108,109,110;,
3;110,111,108;,
3;112,113,114;,
3;114,115,112;,
3;116,117,118;,
3;118,119,116;,
3;120,121,122;,
3;122,123,120;,
3;124,125,126;,
3;126,127,124;,
3;128,129,130;,
3;130,131,128;,
3;132,133,134;,
3;134,135,132;,
3;136,137,138;,
3;138,139,136;,
3;140,141,142;,
3;142,143,140;,
3;144,145,146;,
3;146,147,144;,
3;148,149,150;,
3;150,151,148;,
3;152,153,154;,
3;154,155,152;,
3;156,157,158;,
3;158,159,156;;
 }
MeshTextureCoords {
 160;
1.000000;1.000000;,
1.000000;0.717808;,
0.000000;0.717808;,
0.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;0.282192;,
1.000000;0.282192;,
0.000000;0.669406;,
1.000000;0.669406;,
0.000000;0.621005;,
1.000000;0.621005;,
0.000000;0.572603;,
1.000000;0.572603;,
0.000000;0.524201;,
1.000000;0.524201;,
0.000000;0.475799;,
1.000000;0.475799;,
0.000000;0.427397;,
1.000000;0.427397;,
0.000000;0.378995;,
1.000000;0.378995;,
0.000000;0.330594;,
1.000000;0.330594;,
1.000000;1.000000;,
1.000000;0.000000;,
0.857143;0.000000;,
0.857143;1.000000;,
0.714286;0.000000;,
0.714286;1.000000;,
0.571429;0.000000;,
0.571429;1.000000;,
0.428571;0.000000;,
0.428571;1.000000;,
0.285714;0.000000;,
0.285714;1.000000;,
0.142857;0.000000;,
0.142857;1.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
0.000000;1.000000;,
0.142857;1.000000;,
0.142857;0.000000;,
0.000000;0.000000;,
0.285714;1.000000;,
0.285714;0.000000;,
0.428571;1.000000;,
0.428571;0.000000;,
0.571429;1.000000;,
0.571429;0.000000;,
0.714286;1.000000;,
0.714286;0.000000;,
0.857143;1.000000;,
0.857143;0.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;1.000000;,
0.142857;1.000000;,
0.142857;0.000000;,
0.000000;0.000000;,
0.142857;1.000000;,
0.285714;1.000000;,
0.285714;0.000000;,
0.142857;0.000000;,
0.285714;1.000000;,
0.428571;1.000000;,
0.428571;0.000000;,
0.285714;0.000000;,
0.428571;1.000000;,
0.571429;1.000000;,
0.571429;0.000000;,
0.428571;0.000000;,
0.571429;1.000000;,
0.714286;1.000000;,
0.714286;0.000000;,
0.571429;0.000000;,
0.714286;1.000000;,
0.857143;1.000000;,
0.857143;0.000000;,
0.714286;0.000000;,
0.857143;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.857143;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
0.142857;1.000000;,
0.142857;0.000000;,
0.000000;0.000000;,
0.142857;1.000000;,
0.285714;1.000000;,
0.285714;0.000000;,
0.142857;0.000000;,
0.285714;1.000000;,
0.428571;1.000000;,
0.428571;0.000000;,
0.285714;0.000000;,
0.428571;1.000000;,
0.571429;1.000000;,
0.571429;0.000000;,
0.428571;0.000000;,
0.571429;1.000000;,
0.714286;1.000000;,
0.714286;0.000000;,
0.571429;0.000000;,
0.714286;1.000000;,
0.857143;1.000000;,
0.857143;0.000000;,
0.714286;0.000000;,
0.857143;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.857143;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
1.000000;1.000000;,
1.000000;0.000000;,
0.000000;0.000000;,
0.000000;1.000000;,
0.000000;0.000000;,
1.000000;0.000000;,
1.000000;1.000000;,
0.000000;1.000000;,
0.000000;0.000000;,
1.000000;0.000000;,
1.000000;1.000000;,
0.000000;1.000000;,
0.000000;0.000000;,
1.000000;0.000000;,
1.000000;1.000000;,
0.000000;1.000000;,
0.000000;0.000000;,
1.000000;0.000000;,
1.000000;1.000000;,
0.000000;1.000000;,
0.000000;0.000000;,
1.000000;0.000000;,
1.000000;1.000000;;
}
}
 }
