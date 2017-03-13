<?xml version="1.0" encoding="UTF-8" ?>
<SCL xmlns="http://www.iec.ch/61850/2006/SCL" xmlns:xsi="http://www.w3.org/2001/XMLSchema" xmlns:kf="http://www.keyvia.cn" xsi:schemaLocation="http://www.iec.ch/61850/2006/SCL">
    <Private type="Substation virtual terminal conection CRC">A46484EF</Private>
    <Header id="Template" version="1.00" toolID="Keyvia Configuration" nameStructure="IEDName">
        <History>
            <Hitem version="1.0" revision="1.0" when="2016-12-08 13:16:18" who="" what="" why="" />
            <Hitem version="1.1" revision="1.0" when="2016-12-08 13:17:37" who="" what="" why="" />
        </History>
    </Header>
    <Substation name="" />
    <Communication>
        <SubNetwork name="MMS-Subnet" type="8-MMS" desc="">
            <ConnectedAP iedName="ZLB1F650" apName="S1">
                <Address>
                    <P type="IP">192.168.1.16</P>
                    <P type="IP-SUBNET">255.255.255.0</P>
                    <P type="IP-GATEWAY">0.0.0.0</P>
                    <P type="OSI-AP-Title">1,1,999,1,1</P>
                    <P type="OSI-AE-Qualifier">12</P>
                    <P type="OSI-PSEL">00000001</P>
                    <P type="OSI-SSEL">0001</P>
                    <P type="OSI-TSEL">0001</P>
                </Address>
                <GSE ldInst="F650" cbName="gcb01">
                    <Address>
                        <P type="VLAN-ID">0</P>
                        <P type="VLAN-PRIORITY">4</P>
                        <P type="MAC-Address">00-00-00-00-00-00</P>
                        <P type="APPID">1</P>
                    </Address>
                </GSE>
            </ConnectedAP>
        </SubNetwork>
        <SubNetwork name="GOOSE-Subnet" type="IECGOOSE" desc="" />
        <SubNetwork name="SMV-Subnet" type="SMV" desc="" />
    </Communication>
    <IED name="ZLB1F650" desc="" type="F650 Bay Controller" manufacturer="XDGE" configVersion="1.0">
        <Private type="UseDoiDai">false</Private>
        <Services>
            <DynAssociation />
            <GetDirectory />
            <GetDataObjectDefinition />
            <DataObjectDirectory />
            <GetDataSetValue />
            <DataSetDirectory />
            <ConfDataSet max="20" maxAttributes="64" />
            <ReadWrite />
            <ConfReportControl max="20" />
            <GetCBValues />
            <ReportSettings cbName="Fix" datSet="Fix" rptID="Dyn" optFields="Dyn" bufTime="Dyn" trgOps="Dyn" intgPd="Dyn" />
            <GSESettings cbName="Fix" datSet="Fix" appID="Dyn" />
            <ConfLNs fixPrefix="true" fixLnInst="true" />
            <GSSE max="1" />
            <GOOSE max="4" />
            <FileHandling />
            <Private type="IED virtual terminal conection CRC">E8151141</Private>
        </Services>
        <AccessPoint name="S1">
            <Server>
                <Authentication none="true" />
                <LDevice inst="F650">
                    <Private type="Internal_instance">inst=&quot;F650&quot;</Private>
                    <LN0 desc="description" lnType="geLLN0" lnClass="LLN0" inst="">
                        <DataSet name="eveGGIO1$ST" desc="GGIO Inputs States">
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind1" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind2" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind3" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind4" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind5" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind6" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind7" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind8" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind9" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind10" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind11" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind12" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind13" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind14" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind15" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind16" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind17" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind18" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind19" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind20" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind21" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind22" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind23" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind24" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind25" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind26" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind27" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind28" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind29" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind30" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind31" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind32" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind33" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind34" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind35" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind36" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind37" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind38" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind39" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind40" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind41" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind42" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind43" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind44" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind45" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind46" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind47" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind48" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind49" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind50" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind51" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind52" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind53" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind54" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind55" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind56" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind57" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind58" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind59" fc="ST" />
                            <FCDA ldInst="F650" prefix="eve" lnInst="1" lnClass="GGIO" doName="Ind60" fc="ST" />
                        </DataSet>
                        <DataSet name="MMXU1$MX" desc="MMXU Analogue Values">
                            <FCDA ldInst="F650" prefix="" lnInst="1" lnClass="MMXU" doName="A.phsA" fc="MX" daName="cVal.mag.f" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="A.phsB" fc="MX" daName="cVal.mag.f" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="A.phsC" fc="MX" daName="cVal.mag.f" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="A.net" daName="cVal.mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="PPV.phsAB" daName="cVal.mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="PPV.phsBC" daName="cVal.mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="PPV.phsCA" daName="cVal.mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="TotVAr" daName="mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="TotW" daName="mag.f" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnClass="MMXU" lnInst="1" doName="TotPF" daName="mag.f" fc="MX" />
                        </DataSet>
                        <DataSet name="MMTR1_Counters" desc="MMTR Counters">
                            <FCDA ldInst="F650" prefix="" lnInst="1" lnClass="MMTR" doName="CntPsWh" fc="MX" />
                            <FCDA ldInst="F650" prefix="" lnInst="1" lnClass="MMTR" doName="CntPsVArh" fc="MX" />
                        </DataSet>
                        <DataSet name="GOOSE1" desc="GOOSE CONF1">
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind1" daName="stVal" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind1" daName="q" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind2" daName="stVal" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind2" daName="q" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind3" daName="stVal" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind3" daName="q" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind4" daName="stVal" fc="ST" />
                            <FCDA ldInst="F650" prefix="rou" lnInst="1" lnClass="GGIO" doName="Ind4" daName="q" fc="ST" />
                        </DataSet>
                        <ReportControl name="brcbSTA01" desc="eveGGIO Control Block" rptID="Inputs1" datSet="eveGGIO1$ST" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <ReportControl name="urcbSTA01" desc="eveGGIO Control Block" rptID="UnbufInps1" datSet="eveGGIO1$ST" confRev="1" buffered="false">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" configRef="true" />
                            <RptEnabled max="5" />
                        </ReportControl>
                        <ReportControl name="brcbSTF01" desc="MMTR1 Control Block" rptID="PulseCounters1" datSet="MMTR1_Counters" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <ReportControl name="urcbSTF01" desc="MMTR1 Control Block" rptID="UnbufPulseCounters1" datSet="MMTR1_Counters" confRev="1" buffered="false">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" configRef="true" />
                            <RptEnabled max="5" />
                        </ReportControl>
                        <ReportControl name="brcbMXA01" desc="MMXU1 Control Block" rptID="Meas1" datSet="MMXU1$MX" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <ReportControl name="urcbMXA01" desc="MMXU1 Control Block" rptID="UnbufMeas1" datSet="MMXU1$MX" confRev="1" buffered="false">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" configRef="true" />
                            <RptEnabled max="5" />
                        </ReportControl>
                        <ReportControl name="brcbSTA02" desc="eveGGIO Control Block" rptID="Inputs2" datSet="eveGGIO1$ST" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <ReportControl name="brcbMXA02" desc="MMXU1 Control Block" rptID="Meas2" datSet="MMXU1$MX" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <ReportControl name="brcbSTF02" desc="MMTR1 Control Block" rptID="PulseCounters2" datSet="MMTR1_Counters" confRev="1" buffered="true" bufTime="60">
                            <TrgOps dchg="true" qchg="false" dupd="false" period="true" />
                            <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" />
                            <RptEnabled max="1" />
                        </ReportControl>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <GSEControl name="scb" appID="geLLN0" type="GSSE" />
                        <GSEControl name="gcb01" datSet="GOOSE1" appID="geLLN0" confRev="1" />
                    </LN0>
                    <LN inst="1" lnClass="LPHD" lnType="geLPHD">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                    </LN>
                    <LN inst="1" lnClass="MMXU" lnType="geMMXU">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TotW">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TotVAr">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TotVA">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TotPF">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Hz">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PPV">
                            <SDI name="phsAB">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsBC">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsCA">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PhV">
                            <SDI name="phsA">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsB">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsC">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="neut">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="A">
                            <SDI name="phsA">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsB">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="phsC">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="neut">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="net">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="res">
                                <DAI name="db" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                                <DAI name="dbAng" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="AuxV">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                            <DAI name="dbAng" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BusHz">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="MSQI" lnType="geMSQI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SeqA">
                            <SDI name="c1">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="c2">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="c3">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="SeqV">
                            <SDI name="c1">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="c2">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                            <SDI name="c3">
                                <DAI name="db" valKind="Set">
                                    <Val>10000</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="MMTR" lnType="geMMTR">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="CntPsWh">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="CntNgWh">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="CntPsVArh">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="CntNgVArh">
                            <DAI name="db" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="5" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;5&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="6" lnClass="PIOC" lnType="gePhsPIOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;6&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PIOC" lnType="geNdPIOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PIOC" lnType="geNdPIOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PIOC" lnType="geNdPIOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PIOC" lnType="geGndPIOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PIOC" lnType="geGndPIOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PIOC" lnType="geGndPIOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PIOC" lnType="geGndPIOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PIOC" lnType="geGndPIOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PIOC" lnType="geGndPIOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PIOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="5" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;5&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="6" lnClass="PTOC" lnType="gePhsPTOC" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;6&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="VolRst">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOC" lnType="geNdPTOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOC" lnType="geNdPTOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOC" lnType="geNdPTOC" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOC" lnType="geGndPTOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOC" lnType="geGndPTOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOC" lnType="geGndPTOC" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.05</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOC" lnType="geGndPTOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOC" lnType="geGndPTOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOC" lnType="geGndPTOC" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOCEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMagTyp">
                            <DAI name="setVal" valKind="Set">
                                <Val>phasor</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.005</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmACrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>ANSI Extremly Inverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>instantaneous</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="RDIR" lnType="gePhsRDIR" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="RDIR" lnType="gePhsRDIR" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="RDIR" lnType="gePhsRDIR" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="RDIR" lnType="geNdRDIR" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="RDIR" lnType="geNdRDIR" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="RDIR" lnType="geNdRDIR" prefix="nd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;nd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="RDIR" lnType="geGndRDIR" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="RDIR" lnType="geGndRDIR" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="RDIR" lnType="geGndRDIR" prefix="gnd">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;gnd&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PolQty">
                            <DAI name="setVal" valKind="Set">
                                <Val>Zero Sequence Voltage</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="RDIR" lnType="geHseRDIR" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="RDIR" lnType="geHseRDIR" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="RDIR" lnType="geHseRDIR" prefix="hse">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;hse&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RDIREna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ChrAng">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PolOpMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>reverse</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>permission</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkValV">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOF" lnType="gePTOF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOF" lnType="gePTOF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOF" lnType="gePTOF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTUF" lnType="gePTUF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTUF" lnType="gePTUF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTUF" lnType="gePTUF">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUFEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>20</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>30</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTUV" lnType="gePhsPTUV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>phase-phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="DeaLinVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BkrMon">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTUV" lnType="gePhsPTUV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>phase-phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="DeaLinVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BkrMon">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTUV" lnType="gePhsPTUV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="InMod">
                            <DAI name="setVal" valKind="Set">
                                <Val>phase-phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="DeaLinVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BkrMon">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTUV" lnType="geAuxPTUV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTUV" lnType="geAuxPTUV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTUV" lnType="geAuxPTUV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTUVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="TmVCrv">
                            <DAI name="setCharact" valKind="Set">
                                <Val>DefiniteTime</Val>
                            </DAI>
                        </DOI>
                        <DOI name="TmMult">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOV" lnType="gePhsPTOV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOV" lnType="gePhsPTOV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOV" lnType="gePhsPTOV" prefix="phs">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;phs&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PhLogic">
                            <DAI name="setVal" valKind="Set">
                                <Val>any phase</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOV" lnType="geAuxPTOV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOV" lnType="geAuxPTOV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOV" lnType="geAuxPTOV" prefix="aux">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;aux&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="5" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;5&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="6" lnClass="PTOV" lnType="geNeutPTOV" prefix="neu">
                        <Private type="Internal_prefix_and_instance">inst=&quot;6&quot;,prefix=&quot;neu&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="PTOVEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="StrVal">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>3</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="OpDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RsDlTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="RREC" lnType="geRREC">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RRECEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="MaxNumShot">
                            <DAI name="setVal" valKind="Set">
                                <Val>1 Shot</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Rec1Tmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Rec2Tmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Rec3Tmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Rec4Tmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="RclTmms">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="CondEna">
                            <DAI name="setVal" valKind="Set">
                                <Val>0</Val>
                            </DAI>
                        </DOI>
                        <DOI name="HoldTmms">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="RsTmms">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="XCBR" lnType="geXCBR">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                            <DAI name="sboTimeout" valKind="Set">
                                <Val>30000</Val>
                            </DAI>
                            <DAI name="sboClass" valKind="RO">
                                <Val>operate-once</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkOpn">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkCls">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="ThAlSwA">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="SumSwATmms">
                            <SDI name="setMag">
                                <DAI name="f" valKind="Set">
                                    <Val>0.03</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="ExNumTr">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>0</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                        <DOI name="ExNumTr1hr">
                            <SDI name="setMag">
                                <DAI name="i" valKind="Set">
                                    <Val>1</Val>
                                </DAI>
                            </SDI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="CSWI" lnType="geCSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                            <DAI name="sboTimeout" valKind="Set">
                                <Val>30000</Val>
                            </DAI>
                            <DAI name="sboClass" valKind="RO">
                                <Val>operate-once</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="CSWI" lnType="geCSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                            <DAI name="sboTimeout" valKind="Set">
                                <Val>30000</Val>
                            </DAI>
                            <DAI name="sboClass" valKind="RO">
                                <Val>operate-once</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="CSWI" lnType="geCSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                            <DAI name="sboTimeout" valKind="Set">
                                <Val>30000</Val>
                            </DAI>
                            <DAI name="sboClass" valKind="RO">
                                <Val>operate-once</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="CSWI" lnType="geCSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                            <DAI name="sboTimeout" valKind="Set">
                                <Val>30000</Val>
                            </DAI>
                            <DAI name="sboClass" valKind="RO">
                                <Val>operate-once</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="XSWI" lnType="geXSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkOpn">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkCls">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="XSWI" lnType="geXSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkOpn">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkCls">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="XSWI" lnType="geXSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkOpn">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkCls">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="XSWI" lnType="geXSWI">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="Pos">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkOpn">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="BlkCls">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="GGIO" lnType="geBoardGGIO">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn1">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn2">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn3">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn4">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn5">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn6">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn7">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn8">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="2" lnClass="GGIO" lnType="geBoardGGIO">
                        <Private type="Internal_prefix_and_instance">inst=&quot;2&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn1">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn2">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn3">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn4">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn5">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn6">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn7">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn8">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="3" lnClass="GGIO" lnType="geBoardGGIO">
                        <Private type="Internal_prefix_and_instance">inst=&quot;3&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn1">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn2">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn3">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn4">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn5">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn6">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn7">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn8">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="4" lnClass="GGIO" lnType="geBoardGGIO">
                        <Private type="Internal_prefix_and_instance">inst=&quot;4&quot;,prefix=&quot;&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn1">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn2">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn3">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn4">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn5">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn6">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn7">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn8">
                            <DAI name="db" valKind="Set">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="GGIO" lnType="geVirtualGGIO" prefix="vin">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;vin&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO1">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO2">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO3">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO4">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO5">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO6">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO7">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO8">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO9">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO10">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO11">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO12">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO13">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO14">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO15">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="DPCSO16">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO1">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO2">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO3">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO4">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO5">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO6">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO7">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO8">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO9">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO10">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO11">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO12">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO13">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO14">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO15">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO16">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO17">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO18">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO19">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO20">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO21">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO22">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO23">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO24">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO25">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO26">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO27">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO28">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO29">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO30">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO31">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO32">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO33">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO34">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO35">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO36">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO37">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO38">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO39">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO40">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO41">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO42">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO43">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO44">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO45">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO46">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO47">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO48">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO49">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO50">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO51">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO52">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO53">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO54">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO55">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO56">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO57">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO58">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO59">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO60">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO61">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO62">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO63">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                        <DOI name="SPCSO64">
                            <DAI name="ctlModel" valKind="Set">
                                <Val>direct-with-normal-security</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="GGIO" lnType="geEventsGGIO" prefix="eve">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;eve&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="GGIO" lnType="geRemoteInputsGGIO" prefix="rin">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;rin&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn1">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn2">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn3">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn4">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn5">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn6">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn7">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn8">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn9">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn10">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn11">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn12">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn13">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn14">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn15">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                        <DOI name="AnIn16">
                            <DAI name="db" valKind="RO">
                                <Val>10000</Val>
                            </DAI>
                        </DOI>
                    </LN>
                    <LN inst="1" lnClass="GGIO" lnType="geRemoteOutputsGGIO" prefix="rou">
                        <Private type="Internal_prefix_and_instance">inst=&quot;1&quot;,prefix=&quot;rou&quot;</Private>
                        <DOI name="Mod">
                            <DAI name="ctlModel" valKind="RO">
                                <Val>status-only</Val>
                            </DAI>
                        </DOI>
                    </LN>
                </LDevice>
            </Server>
        </AccessPoint>
    </IED>
    <DataTypeTemplates>
        <LNodeType id="geLPHD" lnClass="LPHD">
            <DO name="PhyNam" type="geDPL" />
            <DO name="PhyHealth" type="geHealthINS" />
            <DO name="Proxy" type="geSPS" />
        </LNodeType>
        <LNodeType id="geLLN0" lnClass="LLN0">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL_1" />
            <DO name="Loc" type="geSPS" />
            <DO name="OpTmh" type="geINS" />
        </LNodeType>
        <LNodeType id="geMMXU" lnClass="MMXU">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="TotW" type="geFloatMV" />
            <DO name="TotVAr" type="geFloatMV" />
            <DO name="TotVA" type="geFloatMV" />
            <DO name="TotPF" type="geFloatMV" />
            <DO name="Hz" type="geFloatMV" />
            <DO name="PPV" type="geFloatDEL" />
            <DO name="PhV" type="geFloatPhsWYE" />
            <DO name="A" type="geFloatWYE" />
            <DO name="AuxV" type="geFloatCMV_1" />
            <DO name="BusHz" type="geFloatMV_1" />
        </LNodeType>
        <LNodeType id="geMSQI" lnClass="MSQI">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="SeqA" type="geFloatSEQ" />
            <DO name="SeqV" type="geFloatSEQ" />
        </LNodeType>
        <LNodeType id="geMMTR" lnClass="MMTR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="SupWh" type="geBCR" />
            <DO name="SupVArh" type="geBCR" />
            <DO name="DmdWh" type="geBCR" />
            <DO name="DmdVArh" type="geBCR" />
            <DO name="CntPsWh" type="geFloatMV_1" />
            <DO name="CntNgWh" type="geFloatMV_1" />
            <DO name="CntPsVArh" type="geFloatMV_1" />
            <DO name="CntNgVArh" type="geFloatMV_1" />
        </LNodeType>
        <LNodeType id="gePhsPIOC" lnClass="PIOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="gePhsACD" />
            <DO name="Op" type="gePhsACT" />
            <DO name="Blk" type="gePhsACT_1" />
            <DO name="PIOCEna" type="geSPG" />
            <DO name="InMagTyp" type="geING_1" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
        </LNodeType>
        <LNodeType id="geNdPIOC" lnClass="PIOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="PIOCEna" type="geSPG" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
        </LNodeType>
        <LNodeType id="geGndPIOC" lnClass="PIOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="PIOCEna" type="geSPG" />
            <DO name="InMagTyp" type="geING_1" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
        </LNodeType>
        <LNodeType id="geBoardGGIO" lnClass="GGIO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="BoardSt" type="geSPS_1" />
            <DO name="Ind1" type="geSPS" />
            <DO name="Ind2" type="geSPS" />
            <DO name="Ind3" type="geSPS" />
            <DO name="Ind4" type="geSPS" />
            <DO name="Ind5" type="geSPS" />
            <DO name="Ind6" type="geSPS" />
            <DO name="Ind7" type="geSPS" />
            <DO name="Ind8" type="geSPS" />
            <DO name="Ind9" type="geSPS" />
            <DO name="Ind10" type="geSPS" />
            <DO name="Ind11" type="geSPS" />
            <DO name="Ind12" type="geSPS" />
            <DO name="Ind13" type="geSPS" />
            <DO name="Ind14" type="geSPS" />
            <DO name="Ind15" type="geSPS" />
            <DO name="Ind16" type="geSPS" />
            <DO name="Ind17" type="geSPS" />
            <DO name="Ind18" type="geSPS" />
            <DO name="Ind19" type="geSPS" />
            <DO name="Ind20" type="geSPS" />
            <DO name="Ind21" type="geSPS" />
            <DO name="Ind22" type="geSPS" />
            <DO name="Ind23" type="geSPS" />
            <DO name="Ind24" type="geSPS" />
            <DO name="Ind25" type="geSPS" />
            <DO name="Ind26" type="geSPS" />
            <DO name="Ind27" type="geSPS" />
            <DO name="Ind28" type="geSPS" />
            <DO name="Ind29" type="geSPS" />
            <DO name="Ind30" type="geSPS" />
            <DO name="Ind31" type="geSPS" />
            <DO name="Ind32" type="geSPS" />
            <DO name="Ind33" type="geSPS" />
            <DO name="Ind34" type="geSPS" />
            <DO name="Ind35" type="geSPS" />
            <DO name="Ind36" type="geSPS" />
            <DO name="Ind37" type="geSPS" />
            <DO name="Ind38" type="geSPS" />
            <DO name="Ind39" type="geSPS" />
            <DO name="Ind40" type="geSPS" />
            <DO name="Ind41" type="geSPS" />
            <DO name="Ind42" type="geSPS" />
            <DO name="Ind43" type="geSPS" />
            <DO name="Ind44" type="geSPS" />
            <DO name="Ind45" type="geSPS" />
            <DO name="Ind46" type="geSPS" />
            <DO name="Ind47" type="geSPS" />
            <DO name="Ind48" type="geSPS" />
            <DO name="AnIn1" type="geFloatMV" />
            <DO name="AnIn2" type="geFloatMV" />
            <DO name="AnIn3" type="geFloatMV" />
            <DO name="AnIn4" type="geFloatMV" />
            <DO name="AnIn5" type="geFloatMV" />
            <DO name="AnIn6" type="geFloatMV" />
            <DO name="AnIn7" type="geFloatMV" />
            <DO name="AnIn8" type="geFloatMV" />
        </LNodeType>
        <LNodeType id="geVirtualGGIO" lnClass="GGIO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="DPCSO1" type="geDPC" />
            <DO name="DPCSO2" type="geDPC" />
            <DO name="DPCSO3" type="geDPC" />
            <DO name="DPCSO4" type="geDPC" />
            <DO name="DPCSO5" type="geDPC" />
            <DO name="DPCSO6" type="geDPC" />
            <DO name="DPCSO7" type="geDPC" />
            <DO name="DPCSO8" type="geDPC" />
            <DO name="DPCSO9" type="geDPC" />
            <DO name="DPCSO10" type="geDPC" />
            <DO name="DPCSO11" type="geDPC" />
            <DO name="DPCSO12" type="geDPC" />
            <DO name="DPCSO13" type="geDPC" />
            <DO name="DPCSO14" type="geDPC" />
            <DO name="DPCSO15" type="geDPC" />
            <DO name="DPCSO16" type="geDPC" />
            <DO name="SPCSO1" type="geSPC" />
            <DO name="SPCSO2" type="geSPC" />
            <DO name="SPCSO3" type="geSPC" />
            <DO name="SPCSO4" type="geSPC" />
            <DO name="SPCSO5" type="geSPC" />
            <DO name="SPCSO6" type="geSPC" />
            <DO name="SPCSO7" type="geSPC" />
            <DO name="SPCSO8" type="geSPC" />
            <DO name="SPCSO9" type="geSPC" />
            <DO name="SPCSO10" type="geSPC" />
            <DO name="SPCSO11" type="geSPC" />
            <DO name="SPCSO12" type="geSPC" />
            <DO name="SPCSO13" type="geSPC" />
            <DO name="SPCSO14" type="geSPC" />
            <DO name="SPCSO15" type="geSPC" />
            <DO name="SPCSO16" type="geSPC" />
            <DO name="SPCSO17" type="geSPC" />
            <DO name="SPCSO18" type="geSPC" />
            <DO name="SPCSO19" type="geSPC" />
            <DO name="SPCSO20" type="geSPC" />
            <DO name="SPCSO21" type="geSPC" />
            <DO name="SPCSO22" type="geSPC" />
            <DO name="SPCSO23" type="geSPC" />
            <DO name="SPCSO24" type="geSPC" />
            <DO name="SPCSO25" type="geSPC" />
            <DO name="SPCSO26" type="geSPC" />
            <DO name="SPCSO27" type="geSPC" />
            <DO name="SPCSO28" type="geSPC" />
            <DO name="SPCSO29" type="geSPC" />
            <DO name="SPCSO30" type="geSPC" />
            <DO name="SPCSO31" type="geSPC" />
            <DO name="SPCSO32" type="geSPC" />
            <DO name="SPCSO33" type="geSPC" />
            <DO name="SPCSO34" type="geSPC" />
            <DO name="SPCSO35" type="geSPC" />
            <DO name="SPCSO36" type="geSPC" />
            <DO name="SPCSO37" type="geSPC" />
            <DO name="SPCSO38" type="geSPC" />
            <DO name="SPCSO39" type="geSPC" />
            <DO name="SPCSO40" type="geSPC" />
            <DO name="SPCSO41" type="geSPC" />
            <DO name="SPCSO42" type="geSPC" />
            <DO name="SPCSO43" type="geSPC" />
            <DO name="SPCSO44" type="geSPC" />
            <DO name="SPCSO45" type="geSPC" />
            <DO name="SPCSO46" type="geSPC" />
            <DO name="SPCSO47" type="geSPC" />
            <DO name="SPCSO48" type="geSPC" />
            <DO name="SPCSO49" type="geSPC" />
            <DO name="SPCSO50" type="geSPC" />
            <DO name="SPCSO51" type="geSPC" />
            <DO name="SPCSO52" type="geSPC" />
            <DO name="SPCSO53" type="geSPC" />
            <DO name="SPCSO54" type="geSPC" />
            <DO name="SPCSO55" type="geSPC" />
            <DO name="SPCSO56" type="geSPC" />
            <DO name="SPCSO57" type="geSPC" />
            <DO name="SPCSO58" type="geSPC" />
            <DO name="SPCSO59" type="geSPC" />
            <DO name="SPCSO60" type="geSPC" />
            <DO name="SPCSO61" type="geSPC" />
            <DO name="SPCSO62" type="geSPC" />
            <DO name="SPCSO63" type="geSPC" />
            <DO name="SPCSO64" type="geSPC" />
        </LNodeType>
        <LNodeType id="geEventsGGIO" lnClass="GGIO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Ind1" type="geSPS" />
            <DO name="Ind2" type="geSPS" />
            <DO name="Ind3" type="geSPS" />
            <DO name="Ind4" type="geSPS" />
            <DO name="Ind5" type="geSPS" />
            <DO name="Ind6" type="geSPS" />
            <DO name="Ind7" type="geSPS" />
            <DO name="Ind8" type="geSPS" />
            <DO name="Ind9" type="geSPS" />
            <DO name="Ind10" type="geSPS" />
            <DO name="Ind11" type="geSPS" />
            <DO name="Ind12" type="geSPS" />
            <DO name="Ind13" type="geSPS" />
            <DO name="Ind14" type="geSPS" />
            <DO name="Ind15" type="geSPS" />
            <DO name="Ind16" type="geSPS" />
            <DO name="Ind17" type="geSPS" />
            <DO name="Ind18" type="geSPS" />
            <DO name="Ind19" type="geSPS" />
            <DO name="Ind20" type="geSPS" />
            <DO name="Ind21" type="geSPS" />
            <DO name="Ind22" type="geSPS" />
            <DO name="Ind23" type="geSPS" />
            <DO name="Ind24" type="geSPS" />
            <DO name="Ind25" type="geSPS" />
            <DO name="Ind26" type="geSPS" />
            <DO name="Ind27" type="geSPS" />
            <DO name="Ind28" type="geSPS" />
            <DO name="Ind29" type="geSPS" />
            <DO name="Ind30" type="geSPS" />
            <DO name="Ind31" type="geSPS" />
            <DO name="Ind32" type="geSPS" />
            <DO name="Ind33" type="geSPS" />
            <DO name="Ind34" type="geSPS" />
            <DO name="Ind35" type="geSPS" />
            <DO name="Ind36" type="geSPS" />
            <DO name="Ind37" type="geSPS" />
            <DO name="Ind38" type="geSPS" />
            <DO name="Ind39" type="geSPS" />
            <DO name="Ind40" type="geSPS" />
            <DO name="Ind41" type="geSPS" />
            <DO name="Ind42" type="geSPS" />
            <DO name="Ind43" type="geSPS" />
            <DO name="Ind44" type="geSPS" />
            <DO name="Ind45" type="geSPS" />
            <DO name="Ind46" type="geSPS" />
            <DO name="Ind47" type="geSPS" />
            <DO name="Ind48" type="geSPS" />
            <DO name="Ind49" type="geSPS" />
            <DO name="Ind50" type="geSPS" />
            <DO name="Ind51" type="geSPS" />
            <DO name="Ind52" type="geSPS" />
            <DO name="Ind53" type="geSPS" />
            <DO name="Ind54" type="geSPS" />
            <DO name="Ind55" type="geSPS" />
            <DO name="Ind56" type="geSPS" />
            <DO name="Ind57" type="geSPS" />
            <DO name="Ind58" type="geSPS" />
            <DO name="Ind59" type="geSPS" />
            <DO name="Ind60" type="geSPS" />
            <DO name="Ind61" type="geSPS" />
            <DO name="Ind62" type="geSPS" />
            <DO name="Ind63" type="geSPS" />
            <DO name="Ind64" type="geSPS" />
            <DO name="Ind65" type="geSPS" />
            <DO name="Ind66" type="geSPS" />
            <DO name="Ind67" type="geSPS" />
            <DO name="Ind68" type="geSPS" />
            <DO name="Ind69" type="geSPS" />
            <DO name="Ind70" type="geSPS" />
            <DO name="Ind71" type="geSPS" />
            <DO name="Ind72" type="geSPS" />
            <DO name="Ind73" type="geSPS" />
            <DO name="Ind74" type="geSPS" />
            <DO name="Ind75" type="geSPS" />
            <DO name="Ind76" type="geSPS" />
            <DO name="Ind77" type="geSPS" />
            <DO name="Ind78" type="geSPS" />
            <DO name="Ind79" type="geSPS" />
            <DO name="Ind80" type="geSPS" />
            <DO name="Ind81" type="geSPS" />
            <DO name="Ind82" type="geSPS" />
            <DO name="Ind83" type="geSPS" />
            <DO name="Ind84" type="geSPS" />
            <DO name="Ind85" type="geSPS" />
            <DO name="Ind86" type="geSPS" />
            <DO name="Ind87" type="geSPS" />
            <DO name="Ind88" type="geSPS" />
            <DO name="Ind89" type="geSPS" />
            <DO name="Ind90" type="geSPS" />
            <DO name="Ind91" type="geSPS" />
            <DO name="Ind92" type="geSPS" />
            <DO name="Ind93" type="geSPS" />
            <DO name="Ind94" type="geSPS" />
            <DO name="Ind95" type="geSPS" />
            <DO name="Ind96" type="geSPS" />
            <DO name="Ind97" type="geSPS" />
            <DO name="Ind98" type="geSPS" />
            <DO name="Ind99" type="geSPS" />
            <DO name="Ind100" type="geSPS" />
            <DO name="Ind101" type="geSPS" />
            <DO name="Ind102" type="geSPS" />
            <DO name="Ind103" type="geSPS" />
            <DO name="Ind104" type="geSPS" />
            <DO name="Ind105" type="geSPS" />
            <DO name="Ind106" type="geSPS" />
            <DO name="Ind107" type="geSPS" />
            <DO name="Ind108" type="geSPS" />
            <DO name="Ind109" type="geSPS" />
            <DO name="Ind110" type="geSPS" />
            <DO name="Ind111" type="geSPS" />
            <DO name="Ind112" type="geSPS" />
            <DO name="Ind113" type="geSPS" />
            <DO name="Ind114" type="geSPS" />
            <DO name="Ind115" type="geSPS" />
            <DO name="Ind116" type="geSPS" />
            <DO name="Ind117" type="geSPS" />
            <DO name="Ind118" type="geSPS" />
            <DO name="Ind119" type="geSPS" />
            <DO name="Ind120" type="geSPS" />
            <DO name="Ind121" type="geSPS" />
            <DO name="Ind122" type="geSPS" />
            <DO name="Ind123" type="geSPS" />
            <DO name="Ind124" type="geSPS" />
            <DO name="Ind125" type="geSPS" />
            <DO name="Ind126" type="geSPS" />
            <DO name="Ind127" type="geSPS" />
            <DO name="Ind128" type="geSPS" />
            <DO name="Ind129" type="geSPS" />
            <DO name="Ind130" type="geSPS" />
            <DO name="Ind131" type="geSPS" />
            <DO name="Ind132" type="geSPS" />
            <DO name="Ind133" type="geSPS" />
            <DO name="Ind134" type="geSPS" />
            <DO name="Ind135" type="geSPS" />
            <DO name="Ind136" type="geSPS" />
            <DO name="Ind137" type="geSPS" />
            <DO name="Ind138" type="geSPS" />
            <DO name="Ind139" type="geSPS" />
            <DO name="Ind140" type="geSPS" />
            <DO name="Ind141" type="geSPS" />
            <DO name="Ind142" type="geSPS" />
            <DO name="Ind143" type="geSPS" />
            <DO name="Ind144" type="geSPS" />
            <DO name="Ind145" type="geSPS" />
            <DO name="Ind146" type="geSPS" />
            <DO name="Ind147" type="geSPS" />
            <DO name="Ind148" type="geSPS" />
            <DO name="Ind149" type="geSPS" />
            <DO name="Ind150" type="geSPS" />
            <DO name="Ind151" type="geSPS" />
            <DO name="Ind152" type="geSPS" />
            <DO name="Ind153" type="geSPS" />
            <DO name="Ind154" type="geSPS" />
            <DO name="Ind155" type="geSPS" />
            <DO name="Ind156" type="geSPS" />
            <DO name="Ind157" type="geSPS" />
            <DO name="Ind158" type="geSPS" />
            <DO name="Ind159" type="geSPS" />
            <DO name="Ind160" type="geSPS" />
            <DO name="Ind161" type="geSPS" />
            <DO name="Ind162" type="geSPS" />
            <DO name="Ind163" type="geSPS" />
            <DO name="Ind164" type="geSPS" />
            <DO name="Ind165" type="geSPS" />
            <DO name="Ind166" type="geSPS" />
            <DO name="Ind167" type="geSPS" />
            <DO name="Ind168" type="geSPS" />
            <DO name="Ind169" type="geSPS" />
            <DO name="Ind170" type="geSPS" />
            <DO name="Ind171" type="geSPS" />
            <DO name="Ind172" type="geSPS" />
            <DO name="Ind173" type="geSPS" />
            <DO name="Ind174" type="geSPS" />
            <DO name="Ind175" type="geSPS" />
            <DO name="Ind176" type="geSPS" />
            <DO name="Ind177" type="geSPS" />
            <DO name="Ind178" type="geSPS" />
            <DO name="Ind179" type="geSPS" />
            <DO name="Ind180" type="geSPS" />
            <DO name="Ind181" type="geSPS" />
            <DO name="Ind182" type="geSPS" />
            <DO name="Ind183" type="geSPS" />
            <DO name="Ind184" type="geSPS" />
            <DO name="Ind185" type="geSPS" />
            <DO name="Ind186" type="geSPS" />
            <DO name="Ind187" type="geSPS" />
            <DO name="Ind188" type="geSPS" />
            <DO name="Ind189" type="geSPS" />
            <DO name="Ind190" type="geSPS" />
            <DO name="Ind191" type="geSPS" />
            <DO name="Ind192" type="geSPS" />
        </LNodeType>
        <LNodeType id="geRemoteInputsGGIO" lnClass="GGIO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Ind1" type="geSPS" />
            <DO name="Ind2" type="geSPS" />
            <DO name="Ind3" type="geSPS" />
            <DO name="Ind4" type="geSPS" />
            <DO name="Ind5" type="geSPS" />
            <DO name="Ind6" type="geSPS" />
            <DO name="Ind7" type="geSPS" />
            <DO name="Ind8" type="geSPS" />
            <DO name="Ind9" type="geSPS" />
            <DO name="Ind10" type="geSPS" />
            <DO name="Ind11" type="geSPS" />
            <DO name="Ind12" type="geSPS" />
            <DO name="Ind13" type="geSPS" />
            <DO name="Ind14" type="geSPS" />
            <DO name="Ind15" type="geSPS" />
            <DO name="Ind16" type="geSPS" />
            <DO name="Ind17" type="geSPS" />
            <DO name="Ind18" type="geSPS" />
            <DO name="Ind19" type="geSPS" />
            <DO name="Ind20" type="geSPS" />
            <DO name="Ind21" type="geSPS" />
            <DO name="Ind22" type="geSPS" />
            <DO name="Ind23" type="geSPS" />
            <DO name="Ind24" type="geSPS" />
            <DO name="Ind25" type="geSPS" />
            <DO name="Ind26" type="geSPS" />
            <DO name="Ind27" type="geSPS" />
            <DO name="Ind28" type="geSPS" />
            <DO name="Ind29" type="geSPS" />
            <DO name="Ind30" type="geSPS" />
            <DO name="Ind31" type="geSPS" />
            <DO name="Ind32" type="geSPS" />
            <DO name="AnIn1" type="geFloatMV" />
            <DO name="AnIn2" type="geFloatMV" />
            <DO name="AnIn3" type="geFloatMV" />
            <DO name="AnIn4" type="geFloatMV" />
            <DO name="AnIn5" type="geFloatMV" />
            <DO name="AnIn6" type="geFloatMV" />
            <DO name="AnIn7" type="geFloatMV" />
            <DO name="AnIn8" type="geFloatMV" />
            <DO name="AnIn9" type="geIntMV" />
            <DO name="AnIn10" type="geIntMV" />
            <DO name="AnIn11" type="geIntMV" />
            <DO name="AnIn12" type="geIntMV" />
            <DO name="AnIn13" type="geIntMV" />
            <DO name="AnIn14" type="geIntMV" />
            <DO name="AnIn15" type="geIntMV" />
            <DO name="AnIn16" type="geIntMV" />
        </LNodeType>
        <LNodeType id="geRemoteOutputsGGIO" lnClass="GGIO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Ind1" type="geSPS" />
            <DO name="Ind2" type="geSPS" />
            <DO name="Ind3" type="geSPS" />
            <DO name="Ind4" type="geSPS" />
            <DO name="Ind5" type="geSPS" />
            <DO name="Ind6" type="geSPS" />
            <DO name="Ind7" type="geSPS" />
            <DO name="Ind8" type="geSPS" />
            <DO name="Ind9" type="geSPS" />
            <DO name="Ind10" type="geSPS" />
            <DO name="Ind11" type="geSPS" />
            <DO name="Ind12" type="geSPS" />
            <DO name="Ind13" type="geSPS" />
            <DO name="Ind14" type="geSPS" />
            <DO name="Ind15" type="geSPS" />
            <DO name="Ind16" type="geSPS" />
            <DO name="Ind17" type="geSPS" />
            <DO name="Ind18" type="geSPS" />
            <DO name="Ind19" type="geSPS" />
            <DO name="Ind20" type="geSPS" />
            <DO name="Ind21" type="geSPS" />
            <DO name="Ind22" type="geSPS" />
            <DO name="Ind23" type="geSPS" />
            <DO name="Ind24" type="geSPS" />
            <DO name="Ind25" type="geSPS" />
            <DO name="Ind26" type="geSPS" />
            <DO name="Ind27" type="geSPS" />
            <DO name="Ind28" type="geSPS" />
            <DO name="Ind29" type="geSPS" />
            <DO name="Ind30" type="geSPS" />
            <DO name="Ind31" type="geSPS" />
            <DO name="Ind32" type="geSPS" />
        </LNodeType>
        <LNodeType id="gePhsPTOC" lnClass="PTOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="gePhsACD" />
            <DO name="Op" type="gePhsACT" />
            <DO name="Blk" type="gePhsACT_1" />
            <DO name="PTOCEna" type="geSPG" />
            <DO name="InMagTyp" type="geING_1" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="TmACrv" type="geCURVE" />
            <DO name="VolRst" type="geSPG" />
            <DO name="TmMult" type="geFloatASG" />
            <DO name="RsMod" type="geING_2" />
        </LNodeType>
        <LNodeType id="geNdPTOC" lnClass="PTOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="PTOCEna" type="geSPG" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="TmACrv" type="geCURVE" />
            <DO name="TmMult" type="geFloatASG" />
            <DO name="RsMod" type="geING_2" />
        </LNodeType>
        <LNodeType id="geGndPTOC" lnClass="PTOC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="PTOCEna" type="geSPG" />
            <DO name="InMagTyp" type="geING_1" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="TmACrv" type="geCURVE" />
            <DO name="TmMult" type="geFloatASG" />
            <DO name="RsMod" type="geING_2" />
        </LNodeType>
        <LNodeType id="gePhsRDIR" lnClass="RDIR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Dir" type="gePhsACD" />
            <DO name="Op" type="gePhsACT" />
            <DO name="Blk" type="gePhsACT_1" />
            <DO name="BlkIn" type="geGeneralACT_1" />
            <DO name="RDIREna" type="geSPG" />
            <DO name="ChrAng" type="geFloatASG" />
            <DO name="PolOpMod" type="geING_3" />
            <DO name="BlkMod" type="geING_4" />
            <DO name="BlkValV" type="geIntASG" />
        </LNodeType>
        <LNodeType id="geNdRDIR" lnClass="RDIR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Dir" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="BlkIn" type="geNeutACT_1" />
            <DO name="RDIREna" type="geSPG" />
            <DO name="ChrAng" type="geFloatASG" />
            <DO name="PolOpMod" type="geING_3" />
            <DO name="PolQty" type="geING_5" />
            <DO name="BlkMod" type="geING_4" />
            <DO name="BlkValV" type="geIntASG" />
        </LNodeType>
        <LNodeType id="geGndRDIR" lnClass="RDIR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Dir" type="geNeutACD" />
            <DO name="Op" type="geNeutACT" />
            <DO name="Blk" type="geNeutACT_1" />
            <DO name="BlkIn" type="geNeutACT_1" />
            <DO name="RDIREna" type="geSPG" />
            <DO name="ChrAng" type="geFloatASG" />
            <DO name="PolOpMod" type="geING_3" />
            <DO name="PolQty" type="geING_5" />
            <DO name="BlkMod" type="geING_4" />
            <DO name="BlkValV" type="geIntASG" />
        </LNodeType>
        <LNodeType id="geHseRDIR" lnClass="RDIR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Dir" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="BlkIn" type="geGeneralACT_1" />
            <DO name="RDIREna" type="geSPG" />
            <DO name="ChrAng" type="geFloatASG" />
            <DO name="PolOpMod" type="geING_3" />
            <DO name="BlkMod" type="geING_4" />
            <DO name="BlkValV" type="geIntASG" />
        </LNodeType>
        <LNodeType id="gePTOF" lnClass="PTOF">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTOFEna" type="geSPG" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
            <DO name="BlkVal" type="geIntASG" />
        </LNodeType>
        <LNodeType id="gePTUF" lnClass="PTUF">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTUFEna" type="geSPG" />
            <DO name="StrVal" type="geFloatASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
            <DO name="BlkVal" type="geIntASG" />
        </LNodeType>
        <LNodeType id="geXCBR" lnClass="XCBR">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Loc" type="geSPS" />
            <DO name="OpCnt" type="geINS" />
            <DO name="Pos" type="geDPC_1" />
            <DO name="BlkOpn" type="geSPC_1" />
            <DO name="BlkCls" type="geSPC_1" />
            <DO name="SumSwARs" type="geBCR" />
            <DO name="CBOpCap" type="geCBOpCapINS" />
            <DO name="ThAlSwA" type="geFloatASG_1" />
            <DO name="SumSwATmms" type="geFloatASG_1" />
            <DO name="ExNumTr" type="geIntASG_1" />
            <DO name="ExNumTr1hr" type="geIntASG_1" />
        </LNodeType>
        <LNodeType id="geCSWI" lnClass="CSWI">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Pos" type="geDPC_1" />
        </LNodeType>
        <LNodeType id="geXSWI" lnClass="XSWI">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Loc" type="geSPS" />
            <DO name="EEHealth" type="geINS" />
            <DO name="OpCnt" type="geINS" />
            <DO name="Pos" type="geDPC_2" />
            <DO name="BlkOpn" type="geSPC_1" />
            <DO name="BlkCls" type="geSPC_1" />
            <DO name="SwTyp" type="geSwTyp" />
            <DO name="SwOpCap" type="geSwOpCap" />
        </LNodeType>
        <LNodeType id="geCILO" lnClass="CILO">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="EnaOpn" type="geSPS" />
            <DO name="EnaCls" type="geSPS" />
        </LNodeType>
        <LNodeType id="gePhsPTUV" lnClass="PTUV">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="StrPhGn" type="gePhsACD_1" />
            <DO name="OpPhGn" type="gePhsACT_1" />
            <DO name="StrPhPh" type="gePhsACD_1" />
            <DO name="OpPhPh" type="gePhsACT_1" />
            <DO name="PTUVEna" type="geSPG" />
            <DO name="InMod" type="geING_7" />
            <DO name="StrVal" type="geIntASG" />
            <DO name="TmVCrv" type="geCURVE_2" />
            <DO name="TmMult" type="geFloatASG" />
            <DO name="DeaLinVal" type="geIntASG" />
            <DO name="PhLogic" type="geING_6" />
            <DO name="BkrMon" type="geSPG" />
        </LNodeType>
        <LNodeType id="geAuxPTUV" lnClass="PTUV">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTUVEna" type="geSPG" />
            <DO name="StrVal" type="geIntASG" />
            <DO name="TmVCrv" type="geCURVE_2" />
            <DO name="TmMult" type="geFloatASG" />
        </LNodeType>
        <LNodeType id="gePhsPTOV" lnClass="PTOV">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="gePhsACD" />
            <DO name="Op" type="gePhsACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTOVEna" type="geSPG" />
            <DO name="StrVal" type="geIntASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
            <DO name="PhLogic" type="geING_6" />
        </LNodeType>
        <LNodeType id="geAuxPTOV" lnClass="PTOV">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTOVEna" type="geSPG" />
            <DO name="StrVal" type="geIntASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
        </LNodeType>
        <LNodeType id="geNeutPTOV" lnClass="PTOV">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Str" type="geGeneralACD" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="Blk" type="geGeneralACT_1" />
            <DO name="PTOVEna" type="geSPG" />
            <DO name="StrVal" type="geIntASG" />
            <DO name="OpDlTmms" type="geING_8" />
            <DO name="RsDlTmms" type="geING_8" />
        </LNodeType>
        <LNodeType id="geRREC" lnClass="RREC">
            <DO name="Mod" type="geModINC" />
            <DO name="Beh" type="geBehINS" />
            <DO name="Health" type="geHealthINS" />
            <DO name="NamPlt" type="geLPL" />
            <DO name="Op" type="geGeneralACT" />
            <DO name="AutoRecSt" type="geAutoRecStINS" />
            <DO name="AutoRecLo" type="geINS_1" />
            <DO name="AutoRecBlk" type="geINS_1" />
            <DO name="RRECEna" type="geSPG" />
            <DO name="MaxNumShot" type="geING_0" />
            <DO name="Rec1Tmms" type="geING_8" />
            <DO name="Rec2Tmms" type="geING_8" />
            <DO name="Rec3Tmms" type="geING_8" />
            <DO name="Rec4Tmms" type="geING_9" />
            <DO name="RclTmms" type="geING_8" />
            <DO name="CondEna" type="geSPG" />
            <DO name="HoldTmms" type="geFloatASG_1" />
            <DO name="RsTmms" type="geFloatASG_1" />
        </LNodeType>
        <DOType id="geIntMV" cdc="MV">
            <DA name="instMag" fc="MX" bType="Struct" type="geIntAnalogueValue" dchg="true" />
            <DA name="mag" fc="MX" bType="Struct" type="geIntAnalogueValue" dchg="true" />
            <DA name="q" fc="MX" bType="Quality" qchg="true" />
            <DA name="t" fc="MX" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="db" fc="CF" bType="INT32U" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatMV" cdc="MV">
            <DA name="instMag" fc="MX" bType="Struct" type="geFloatAnalogueValue" dchg="true" />
            <DA name="mag" fc="MX" bType="Struct" type="geFloatAnalogueValue" dchg="true" />
            <DA name="q" fc="MX" bType="Quality" qchg="true" />
            <DA name="t" fc="MX" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="db" fc="CF" bType="INT32U" />
            <DA name="rangeC" fc="CF" bType="Struct" type="RangeConfig" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatMV_1" cdc="MV">
            <DA name="instMag" fc="MX" bType="Struct" type="geFloatAnalogueValue" dchg="true" />
            <DA name="mag" fc="MX" bType="Struct" type="geFloatAnalogueValue" dchg="true" />
            <DA name="q" fc="MX" bType="Quality" qchg="true" />
            <DA name="t" fc="MX" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="db" fc="CF" bType="INT32U" />
            <DA name="rangeC" fc="CF" bType="Struct" type="RangeConfig" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geFloatWYE" cdc="WYE">
            <SDO name="phsA" type="geFloatCMV" />
            <SDO name="phsB" type="geFloatCMV" />
            <SDO name="phsC" type="geFloatCMV" />
            <SDO name="neut" type="geFloatCMV" />
            <SDO name="net" type="geFloatCMV" />
            <SDO name="res" type="geFloatCMV" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatPhsWYE" cdc="WYE">
            <SDO name="phsA" type="geFloatCMV" />
            <SDO name="phsB" type="geFloatCMV" />
            <SDO name="phsC" type="geFloatCMV" />
            <SDO name="neut" type="geFloatCMV" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatDEL" cdc="DEL">
            <SDO name="phsAB" type="geFloatCMV" />
            <SDO name="phsBC" type="geFloatCMV" />
            <SDO name="phsCA" type="geFloatCMV" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatSEQ" cdc="SEQ">
            <SDO name="c1" type="geFloatMV" />
            <SDO name="c2" type="geFloatMV" />
            <SDO name="c3" type="geFloatMV" />
            <DA name="seqT" fc="MX" bType="Enum" type="seqT" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatCMV" cdc="CMV">
            <DA name="instCVal" fc="MX" bType="Struct" type="geFloatVector" dchg="true" />
            <DA name="cVal" fc="MX" bType="Struct" type="geFloatVector" dchg="true" />
            <DA name="q" fc="MX" bType="Quality" qchg="true" />
            <DA name="t" fc="MX" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="db" fc="CF" bType="INT32U" />
            <DA name="dbAng" fc="CF" bType="INT32U" />
            <DA name="rangeC" fc="CF" bType="Struct" type="RangeConfig" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatCMV_1" cdc="CMV">
            <DA name="instCVal" fc="MX" bType="Struct" type="geFloatVector" dchg="true" />
            <DA name="cVal" fc="MX" bType="Struct" type="geFloatVector" dchg="true" />
            <DA name="q" fc="MX" bType="Quality" qchg="true" />
            <DA name="t" fc="MX" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="db" fc="CF" bType="INT32U" />
            <DA name="dbAng" fc="CF" bType="INT32U" />
            <DA name="rangeC" fc="CF" bType="Struct" type="RangeConfig" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geINS" cdc="INS">
            <DA name="stVal" fc="ST" bType="INT32" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geINS_1" cdc="INS">
            <DA name="stVal" fc="ST" bType="INT32" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geAutoRecStINS" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="AutoRecSt" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geBehINS" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="Beh" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geHealthINS" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="Health" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geCBOpCapINS" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="CBOpCap" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSwOpCap" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="SwOpCap" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSwTyp" cdc="INS">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="SwTyp" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geLPL" cdc="LPL">
            <DA name="vendor" fc="DC" bType="VisString255" />
            <DA name="swRev" fc="DC" bType="VisString255" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="configRev" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geLPL_1" cdc="LPL">
            <DA name="vendor" fc="DC" bType="VisString255" />
            <DA name="swRev" fc="DC" bType="VisString255" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="configRev" fc="DC" bType="VisString255" />
            <DA name="ldNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geDPL" cdc="DPL">
            <DA name="vendor" fc="DC" bType="VisString255" />
            <DA name="hwRev" fc="DC" bType="VisString255" />
            <DA name="swRev" fc="DC" bType="VisString255" />
            <DA name="model" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSPS" cdc="SPS">
            <DA name="stVal" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSPS_1" cdc="SPS">
            <DA name="stVal" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="gePhsACD" cdc="ACD">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirGeneral" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsA" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsA" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsB" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsB" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsC" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsC" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="gePhsACD_1" cdc="ACD">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirGeneral" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsA" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsA" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsB" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsB" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="phsC" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirPhsC" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geNeutACD" cdc="ACD">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirGeneral" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="neut" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirNeut" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geGeneralACD" cdc="ACD">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="dirGeneral" fc="ST" bType="Enum" type="dir" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="gePhsACT" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsA" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsB" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsC" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="gePhsACT_1" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsA" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsB" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="phsC" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geNeutACT" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="neut" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geNeutACT_1" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="neut" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geGeneralACT" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geGeneralACT_1" cdc="ACT">
            <DA name="general" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="origin" fc="ST" bType="Struct" type="Originator" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geIntASG" cdc="ASG">
            <DA name="setMag" fc="SP" bType="Struct" type="geIntAnalogueValue" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="minVal" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="maxVal" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="stepSize" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geIntASG_1" cdc="ASG">
            <DA name="setMag" fc="SP" bType="Struct" type="geIntAnalogueValue" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="minVal" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="maxVal" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="stepSize" fc="CF" bType="Struct" type="geIntAnalogueValue" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geFloatASG" cdc="ASG">
            <DA name="setMag" fc="SP" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="minVal" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="maxVal" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="stepSize" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geFloatASG_1" cdc="ASG">
            <DA name="setMag" fc="SP" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="minVal" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="maxVal" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="stepSize" fc="CF" bType="Struct" type="geFloatAnalogueValue" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geCURVE" cdc="CURVE">
            <DA name="setCharact" fc="SP" bType="Enum" type="setCharact" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geCURVE_2" cdc="CURVE">
            <DA name="setCharact" fc="SP" bType="Enum" type="setCharact_2" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSPG" cdc="SPG">
            <DA name="setVal" fc="SP" bType="BOOLEAN" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geBCR" cdc="BCR">
            <DA name="actVal" fc="ST" bType="INT32" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="units" fc="CF" bType="Struct" type="Unit" />
            <DA name="pulsQty" fc="CF" bType="FLOAT32" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSPC" cdc="SPC">
            <DA name="Oper" fc="CO" bType="Struct" type="geOperate" />
            <DA name="stVal" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geSPC_1" cdc="SPC">
            <DA name="stVal" fc="ST" bType="BOOLEAN" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geDPC" cdc="DPC">
            <DA name="Oper" fc="CO" bType="Struct" type="geOperate" />
            <DA name="stVal" fc="ST" bType="Dbpos" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geDPC_1" cdc="DPC">
            <DA name="SBO" fc="CO" bType="VisString65" />
            <DA name="SBOw" fc="CO" bType="Struct" type="geSBOw" />
            <DA name="Oper" fc="CO" bType="Struct" type="geOperate" />
            <DA name="Cancel" fc="CO" bType="Struct" type="geCancel" />
            <DA name="stVal" fc="ST" bType="Dbpos" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="sboTimeout" fc="CF" bType="INT32U" />
            <DA name="sboClass" fc="CF" bType="Enum" type="sboClass" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geDPC_2" cdc="DPC">
            <DA name="stVal" fc="ST" bType="Dbpos" dchg="true" />
            <DA name="q" fc="ST" bType="Quality" qchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geModINC" cdc="INC">
            <DA name="stVal" fc="ST" bType="Enum" dchg="true" type="Mod" />
            <DA name="q" fc="ST" bType="Quality" dchg="true" />
            <DA name="t" fc="ST" bType="Timestamp" />
            <DA name="ctlModel" fc="CF" bType="Enum" type="ctlModel" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geING_0" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="MaxNumShot" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_1" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="InMagTyp" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_2" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="RsMod" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_3" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="PolOpMod" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_4" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="BlkMod" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_5" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="PolQty" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geING_6" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="PhLogic" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_7" cdc="ING">
            <DA name="setVal" fc="SP" bType="Enum" type="InMod" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DOType id="geING_8" cdc="ING">
            <DA name="setVal" fc="SP" bType="INT32" />
            <DA name="minVal" fc="CF" bType="INT32" />
            <DA name="maxVal" fc="CF" bType="INT32" />
            <DA name="stepSize" fc="CF" bType="INT32U" />
            <DA name="d" fc="DC" bType="VisString255" />
        </DOType>
        <DOType id="geING_9" cdc="ING">
            <DA name="setVal" fc="SP" bType="INT32" />
            <DA name="minVal" fc="CF" bType="INT32" />
            <DA name="maxVal" fc="CF" bType="INT32" />
            <DA name="stepSize" fc="CF" bType="INT32U" />
            <DA name="d" fc="DC" bType="VisString255" />
            <DA name="dataNs" fc="EX" bType="VisString255" />
        </DOType>
        <DAType id="RangeConfig">
            <BDA name="hhLim" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="hLim" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="lLim" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="llLim" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="min" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="max" bType="Struct" type="geFloatAnalogueValue" />
        </DAType>
        <DAType id="geIntVector">
            <BDA name="mag" bType="Struct" type="geIntAnalogueValue" />
        </DAType>
        <DAType id="geFloatVector">
            <BDA name="mag" bType="Struct" type="geFloatAnalogueValue" />
            <BDA name="ang" bType="Struct" type="geFloatAnalogueValue" />
        </DAType>
        <DAType id="geIntAnalogueValue">
            <BDA name="i" bType="INT32" />
        </DAType>
        <DAType id="geFloatAnalogueValue">
            <BDA name="f" bType="FLOAT32" />
        </DAType>
        <DAType id="geOperate">
            <BDA name="ctlVal" bType="BOOLEAN" />
            <BDA name="origin" bType="Struct" type="Originator" />
            <BDA name="ctlNum" bType="INT8U" />
            <BDA name="T" bType="Timestamp" />
            <BDA name="Test" bType="BOOLEAN" />
            <BDA name="Check" bType="Dbpos" />
        </DAType>
        <DAType id="geCancel">
            <BDA name="ctlVal" bType="BOOLEAN" />
            <BDA name="origin" bType="Struct" type="Originator" />
            <BDA name="ctlNum" bType="INT8U" />
            <BDA name="T" bType="Timestamp" />
            <BDA name="Test" bType="BOOLEAN" />
        </DAType>
        <DAType id="geSBOw">
            <BDA name="ctlVal" bType="BOOLEAN" />
            <BDA name="origin" bType="Struct" type="Originator" />
            <BDA name="ctlNum" bType="INT8U" />
            <BDA name="T" bType="Timestamp" />
            <BDA name="Test" bType="BOOLEAN" />
            <BDA name="Check" bType="Dbpos" />
        </DAType>
        <DAType id="Originator">
            <BDA name="orCat" bType="Enum" type="orCategory" />
            <BDA name="orIdent" bType="Octet64" />
        </DAType>
        <DAType id="Unit">
            <BDA name="SIUnit" bType="Enum" type="SIUnit" />
            <BDA name="multiplier" bType="Enum" type="multiplier" />
        </DAType>
        <EnumType id="ctlModel">
            <EnumVal ord="0">status-only</EnumVal>
            <EnumVal ord="1">direct-with-normal-security</EnumVal>
            <EnumVal ord="2">sbo-with-normal-security</EnumVal>
            <EnumVal ord="3">direct-with-enhanced-security</EnumVal>
            <EnumVal ord="4">sbo-with-enhanced-security</EnumVal>
        </EnumType>
        <EnumType id="sboClass">
            <EnumVal ord="0">operate-once</EnumVal>
            <EnumVal ord="1">operate-many</EnumVal>
        </EnumType>
        <EnumType id="orCategory">
            <EnumVal ord="0">not-supported</EnumVal>
            <EnumVal ord="1">bay-control</EnumVal>
            <EnumVal ord="2">station-control</EnumVal>
            <EnumVal ord="3">remote-control</EnumVal>
            <EnumVal ord="4">automatic-bay</EnumVal>
            <EnumVal ord="5">automatic-station</EnumVal>
            <EnumVal ord="6">automatic-remote</EnumVal>
            <EnumVal ord="7">maintenance</EnumVal>
            <EnumVal ord="8">process</EnumVal>
        </EnumType>
        <EnumType id="dir">
            <EnumVal ord="0">unknown</EnumVal>
            <EnumVal ord="1">forward</EnumVal>
            <EnumVal ord="2">backward</EnumVal>
            <EnumVal ord="3">both</EnumVal>
        </EnumType>
        <EnumType id="seqT">
            <EnumVal ord="0">pos-neg-zero</EnumVal>
            <EnumVal ord="1">dir-quad-zero</EnumVal>
        </EnumType>
        <EnumType id="setCharact">
            <EnumVal ord="0" />
            <EnumVal ord="1">ANSI Extremly Inverse</EnumVal>
            <EnumVal ord="2">ANSI Very Inverse</EnumVal>
            <EnumVal ord="3">ANSI Normal Inverse</EnumVal>
            <EnumVal ord="4">ANSI Moderate Inverse</EnumVal>
            <EnumVal ord="5">ANSI Definite Time</EnumVal>
            <EnumVal ord="6">Long-Time Extremely Inverse</EnumVal>
            <EnumVal ord="7">Long-Time Very Inverse</EnumVal>
            <EnumVal ord="8">Long-Time Inverse</EnumVal>
            <EnumVal ord="9">IEC Normal Inverse</EnumVal>
            <EnumVal ord="10">IEC Very Inverse</EnumVal>
            <EnumVal ord="11">IEC Inverse</EnumVal>
            <EnumVal ord="12">IEC Extremely Inverse</EnumVal>
            <EnumVal ord="13">IEC Short-Time Inverse</EnumVal>
            <EnumVal ord="14">IEC Long-Time Inverse</EnumVal>
            <EnumVal ord="15">IEC Definite Time</EnumVal>
            <EnumVal ord="16">Reserved</EnumVal>
            <EnumVal ord="17">Definable curve 1 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="18">Definable curve 2 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="19">Definable curve 3 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="20">Definable curve 4 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="21">Definable curve 5 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="22">Definable curve 6 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="23">Definable curve 7 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="24">Definable curve 8 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="25">Definable curve 9 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="26">Definable curve 10 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="27">Definable curve 11 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="28">Definable curve 12 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="29">Definable curve 13 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="30">Definable curve 14 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="31">Definable curve 15 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="32">Definable curve 16 based on formula [x=f(y,A,B,C,D,E,F)]</EnumVal>
            <EnumVal ord="33">Vendor specific curve 1 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="34">Vendor specific curve 2 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="35">Vendor specific curve 3 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="36">Vendor specific curve 4 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="37">Vendor specific curve 5 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="38">Vendor specific curve 6 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="39">Vendor specific curve 7 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="40">Vendor specific curve 8 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="41">Vendor specific curve 9 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="42">Vendor specific curve 10 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="43">Vendor specific curve 11 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="44">Vendor specific curve 12 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="45">Vendor specific curve 13 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="46">Vendor specific curve 14 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="47">Vendor specific curve 15 defined by n pairs (x,y)</EnumVal>
            <EnumVal ord="48">Vendor specific curve 16 defined by n pairs (x,y)</EnumVal>
        </EnumType>
        <EnumType id="multiplier">
            <EnumVal ord="-24">y</EnumVal>
            <EnumVal ord="-21">z</EnumVal>
            <EnumVal ord="-18">a</EnumVal>
            <EnumVal ord="-15">f</EnumVal>
            <EnumVal ord="-12">p</EnumVal>
            <EnumVal ord="-9">n</EnumVal>
            <EnumVal ord="-6">µ</EnumVal>
            <EnumVal ord="-3">m</EnumVal>
            <EnumVal ord="-2">c</EnumVal>
            <EnumVal ord="-1">d</EnumVal>
            <EnumVal ord="0" />
            <EnumVal ord="1">da</EnumVal>
            <EnumVal ord="2">h</EnumVal>
            <EnumVal ord="3">k</EnumVal>
            <EnumVal ord="6">M</EnumVal>
            <EnumVal ord="9">G</EnumVal>
            <EnumVal ord="12">T</EnumVal>
            <EnumVal ord="15">P</EnumVal>
            <EnumVal ord="18">E</EnumVal>
            <EnumVal ord="21">Z</EnumVal>
            <EnumVal ord="24">Y</EnumVal>
        </EnumType>
        <EnumType id="SIUnit">
            <EnumVal ord="1" />
            <EnumVal ord="2">m</EnumVal>
            <EnumVal ord="3">kg</EnumVal>
            <EnumVal ord="4">s</EnumVal>
            <EnumVal ord="5">A</EnumVal>
            <EnumVal ord="6">K</EnumVal>
            <EnumVal ord="7">mol</EnumVal>
            <EnumVal ord="8">cd</EnumVal>
            <EnumVal ord="9">deg</EnumVal>
            <EnumVal ord="10">rad</EnumVal>
            <EnumVal ord="11">sr</EnumVal>
            <EnumVal ord="21">Gy</EnumVal>
            <EnumVal ord="22">q</EnumVal>
            <EnumVal ord="23">°C</EnumVal>
            <EnumVal ord="24">Sv</EnumVal>
            <EnumVal ord="25">F</EnumVal>
            <EnumVal ord="26">C</EnumVal>
            <EnumVal ord="27">S</EnumVal>
            <EnumVal ord="28">H</EnumVal>
            <EnumVal ord="29">V</EnumVal>
            <EnumVal ord="30">ohm</EnumVal>
            <EnumVal ord="31">J</EnumVal>
            <EnumVal ord="32">N</EnumVal>
            <EnumVal ord="33">Hz</EnumVal>
            <EnumVal ord="34">lx</EnumVal>
            <EnumVal ord="35">Lm</EnumVal>
            <EnumVal ord="36">Wb</EnumVal>
            <EnumVal ord="37">T</EnumVal>
            <EnumVal ord="38">W</EnumVal>
            <EnumVal ord="39">Pa</EnumVal>
            <EnumVal ord="41">m²</EnumVal>
            <EnumVal ord="42">m³</EnumVal>
            <EnumVal ord="43">m/s</EnumVal>
            <EnumVal ord="44">m/s²</EnumVal>
            <EnumVal ord="45">m³/s</EnumVal>
            <EnumVal ord="46">m/m³</EnumVal>
            <EnumVal ord="47">M</EnumVal>
            <EnumVal ord="48">kg/m³</EnumVal>
            <EnumVal ord="49">m²/s</EnumVal>
            <EnumVal ord="50">W/m K</EnumVal>
            <EnumVal ord="51">J/K</EnumVal>
            <EnumVal ord="52">ppm</EnumVal>
            <EnumVal ord="53">1/s</EnumVal>
            <EnumVal ord="54">rad/s</EnumVal>
            <EnumVal ord="61">VA</EnumVal>
            <EnumVal ord="62">Watts</EnumVal>
            <EnumVal ord="63">VAr</EnumVal>
            <EnumVal ord="64">phi</EnumVal>
            <EnumVal ord="65">cos(phi)</EnumVal>
            <EnumVal ord="66">Vs</EnumVal>
            <EnumVal ord="67">V²</EnumVal>
            <EnumVal ord="68">As</EnumVal>
            <EnumVal ord="69">A²</EnumVal>
            <EnumVal ord="70">A²t</EnumVal>
            <EnumVal ord="71">VAh</EnumVal>
            <EnumVal ord="72">Wh</EnumVal>
            <EnumVal ord="73">VArh</EnumVal>
            <EnumVal ord="74">V/Hz</EnumVal>
        </EnumType>
        <EnumType id="Dbpos">
            <EnumVal ord="0">intermediate</EnumVal>
            <EnumVal ord="1">off</EnumVal>
            <EnumVal ord="2">on</EnumVal>
            <EnumVal ord="3">bad</EnumVal>
        </EnumType>
        <EnumType id="AutoRecSt">
            <EnumVal ord="-1">Definite Trip</EnumVal>
            <EnumVal ord="1">Ready</EnumVal>
            <EnumVal ord="2">In Progress</EnumVal>
            <EnumVal ord="3">Successful</EnumVal>
            <EnumVal ord="4">Unsuccessful</EnumVal>
        </EnumType>
        <EnumType id="Beh">
            <EnumVal ord="1">on</EnumVal>
            <EnumVal ord="2">blocked</EnumVal>
            <EnumVal ord="3">test</EnumVal>
            <EnumVal ord="4">test/blocked</EnumVal>
            <EnumVal ord="5">off</EnumVal>
        </EnumType>
        <EnumType id="Mod">
            <EnumVal ord="1">on</EnumVal>
            <EnumVal ord="2">blocked</EnumVal>
            <EnumVal ord="3">test</EnumVal>
            <EnumVal ord="4">test/blocked</EnumVal>
            <EnumVal ord="5">off</EnumVal>
        </EnumType>
        <EnumType id="Health">
            <EnumVal ord="1">Ok</EnumVal>
            <EnumVal ord="2">Warning</EnumVal>
            <EnumVal ord="3">Alarm</EnumVal>
        </EnumType>
        <EnumType id="CBOpCap">
            <EnumVal ord="1">None</EnumVal>
            <EnumVal ord="2">Open</EnumVal>
            <EnumVal ord="3">Close-Open</EnumVal>
            <EnumVal ord="4">Open-Close-Open</EnumVal>
            <EnumVal ord="5">Close-Open-Close-Open</EnumVal>
        </EnumType>
        <EnumType id="PolQty">
            <EnumVal ord="-2">Vendor specific quantity 2</EnumVal>
            <EnumVal ord="-1">Vendor specific quantity 1</EnumVal>
            <EnumVal ord="1">None</EnumVal>
            <EnumVal ord="2">Zero Sequence Current</EnumVal>
            <EnumVal ord="3">Zero Sequence Voltage</EnumVal>
            <EnumVal ord="4">Negative Sequence Voltage</EnumVal>
            <EnumVal ord="5">Phase to Phase Voltages</EnumVal>
            <EnumVal ord="6">Phase to Ground Voltages</EnumVal>
        </EnumType>
        <EnumType id="SwOpCap">
            <EnumVal ord="1">None</EnumVal>
            <EnumVal ord="2">Open</EnumVal>
            <EnumVal ord="3">Close-Open</EnumVal>
            <EnumVal ord="4">Open-Close-Open</EnumVal>
            <EnumVal ord="5">Close-Open-Close-Open</EnumVal>
        </EnumType>
        <EnumType id="SwTyp">
            <EnumVal ord="1">Load Break</EnumVal>
            <EnumVal ord="2">Disconnector</EnumVal>
            <EnumVal ord="3">Earthing Switch</EnumVal>
            <EnumVal ord="4">High Speed Earthing Switch</EnumVal>
        </EnumType>
        <EnumType id="InMagTyp">
            <EnumVal ord="0">phasor</EnumVal>
            <EnumVal ord="1">rms</EnumVal>
        </EnumType>
        <EnumType id="MaxNumShot">
            <EnumVal ord="0">1 Shot</EnumVal>
            <EnumVal ord="1">2 Shots</EnumVal>
            <EnumVal ord="2">3 Shots</EnumVal>
            <EnumVal ord="3">4 Shots</EnumVal>
        </EnumType>
        <EnumType id="RsMod">
            <EnumVal ord="0">instantaneous</EnumVal>
            <EnumVal ord="1">lineal</EnumVal>
        </EnumType>
        <EnumType id="PolOpMod">
            <EnumVal ord="0">reverse</EnumVal>
            <EnumVal ord="1">forward</EnumVal>
        </EnumType>
        <EnumType id="BlkMod">
            <EnumVal ord="0">permission</EnumVal>
            <EnumVal ord="1">block</EnumVal>
        </EnumType>
        <EnumType id="PhLogic">
            <EnumVal ord="0">any phase</EnumVal>
            <EnumVal ord="1">two phases</EnumVal>
            <EnumVal ord="2">all phases</EnumVal>
        </EnumType>
        <EnumType id="InMod">
            <EnumVal ord="0">phase-phase</EnumVal>
            <EnumVal ord="1">phase-ground</EnumVal>
        </EnumType>
        <EnumType id="setCharact_2">
            <EnumVal ord="0">DefiniteTime</EnumVal>
            <EnumVal ord="1">Inverse Time</EnumVal>
        </EnumType>
    </DataTypeTemplates>
</SCL>
