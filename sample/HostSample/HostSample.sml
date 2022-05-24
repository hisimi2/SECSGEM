<XCom 2.4>
<S1F1 P Are You There
>

<S1F2 S Online Data
  <LIST 2 
    <ASCII 10 MDLN>
    <ASCII 10 SOFTREV>
  >
>

<S1F3 P Selected Equipment Status Request(SSR)
  <LIST n 
    <UINT4 1 SVID>
  >
>

<S1F4 S Selected Equipment Status Data(SDD)
  <LIST n 
    <ASCII n SV>
  >
>

<S1F13 P Establish Communications Request
  <LIST 0 >
>

<S1F13 P Establish Communications Request
  <LIST 2 
    <ASCII 10 MDLN>
    <ASCII 10 SOFTREV>
  >
>

<S1F14 S Establish Communications Request ACK
  <LIST 2 
    <BINARY 1 COMMACK>
    <LIST 0 >
  >
>

<S1F14 S Establish Communications Request ACK
  <LIST 2 
    <BINARY 1 COMMACK>
    <LIST 2 
      <ASCII 10 MDLN>
      <ASCII 10 SOFTREV>
    >
  >
>

<S2F13 P Equipment Constant Request
  <LIST n 
    <UINT2 1 ECID>
  >
>

<S2F14 S Equipment Constant Data
    UNDEFINED STRUCTURE
> 

<S2F33 P Report Data
  <LIST 2 
    <LIST 10 
      <INT1 1 Int 1>
      <INT2 1 Int 2>
      <INT4 1 Int 4>
      <INT8 1 Int 8>
      <UINT1 1 Uint 1>
      <UINT2 1 Uint 2>
      <UINT4 1 Uint 4>
      <UINT8 1 Uint 8>
      <FLOAT4 1 Float 4>
      <FLOAT8 1 Float 8>
    >
    <LIST 4 
      <ASCII 100 Ascii>
      <JIS8 100 Jis 8>
      <BINARY 1 Binary>
      <BOOL 1 Bool>
    >
  >
>

<S2F34 S Report Data Ack
  <BINARY 1 RDACK>
>

<S2F41 P Host Command Send (HCS) 
  <LIST 2 
    <ASCII 40 RCMD >
    <LIST 0 # of parameters>
  >
>

<S2F42 S Host Command Acknowledge (HCA) 
	<LIST 2 
		<BINARY 1 HCACK>
		<LIST 0 >
	>
>


<S5F1 P Alarm Report Send (ARS)
  <LIST 3 
    <BINARY 1 ALCD>
    <UINT4 1 ALID>
    <ASCII n ALTX>
  >
>

<S5F2 S Alarm Report Acknowledge (ARA)
  <BINARY 1 ACKC5>
>

<S5F23 P 
  <LIST 12 
    <BOOL n BoolArray>
    <BINARY n BinaryArray>
    <UINT1 n U1Array>
    <UINT2 n U2Array>
    <UINT4 n U4Array>
    <UINT8 n U8Array>
    <INT1 n I1Array>
    <INT2 n I2Array>
    <INT4 n I4Array>
    <INT8 n I8Array>
    <FLOAT4 n F4Array>
    <FLOAT8 n F8Array>
  >
>

<S5F24 S 
  <UINT1 1 ACK5>
>

<S6F11 P Event Report
    UNDEFINED STRUCTURE
> 

<S6F12 S 
  <BINARY 1 ACKC6>
>


<S10F3 P Terminal Display, Single (VTN)
  <LIST 2 
    <BINARY 1 TID>
    <ASCII 80 TEXT>
  >
>

<S10F4 S Terminal Display, Single Acknowledge (VTA)
  <BINARY 1 ACKC10>
>

<S14F1 P GetAttr Request
  <LIST 5 
    <ASCII n OBJSPEC>
    <ASCII n OBJTYPE>
    <LIST n 
      <ASCII n OBJID>
    >
    <LIST n 
      <LIST 3 
        <ASCII n ATTRID>
        <ASCII n ATTRDATA>
        <UINT1 1 ATTRRELN>
      >
    >
    <LIST n 
      <ASCII n ATTRID>
    >
  >
>

<S14F2 S GetAttr Data(GAD)
  <LIST 2 
    <LIST n number of objects
      <LIST 2 
        <ASCII n ObjID >
        <LIST n 
          <LIST 2 number of attrubutes
            <ASCII n ATTRID>
            <ASCII n ATTRDATA>
          >
        >
      >
    >
    <LIST 2 
      <UINT1 1 OBJACK >
      <LIST n number of errors reported
        <LIST 2 
          <UINT1 n ERRCODE>
          <ASCII n ERRTEXT>
        >
      >
    >
  >
>
