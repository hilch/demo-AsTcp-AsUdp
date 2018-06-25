<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio Version=3.0.71.16 SP01?>
<SwConfiguration CpuAddress="SL0" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1" />
  <TaskClass Name="Cyclic#2">
    <Task Name="tcp" Source="tcp.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="udp" Source="udp.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4" />
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <DataObjects />
  <NcDataObjects />
  <VcDataObjects />
  <Binaries />
  <Libraries>
    <LibraryObject Name="AsArCfg" Source="Libraries.AsArCfg.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="AsTcp" Source="Libraries.AsTcp.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="Runtime" Source="Libraries.Runtime.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="Operator" Source="Libraries.Operator.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="Convert" Source="Libraries.Convert.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="AsUdp" Source="Libraries.AsUdp.lby" Memory="UserROM" Language="Binary" />
    <LibraryObject Name="AsString" Source="Libraries.AsString.lby" Memory="UserROM" Language="Binary" />
  </Libraries>
</SwConfiguration>