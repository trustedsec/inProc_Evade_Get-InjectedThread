# inProc_Evade_Get-InjectedThread

This PoC was built using visual studio 2019.  
It gives a demo of internal thread creation of memory injected code that will not trigger a detection using Get-InjectedThread.

## Build instructions
git clone -r https://github.com/trustedsec/inProc_Evade_Get-InjectedThread.git 
open .sln file using visual studio 2019  
build the solution

## Running
Aquire a copy of Get-InjectedThread (https://gist.github.com/jaredcatkinson/23905d34537ce4b5b1818c3e6405c1d2)  
Start powershell and import Get-InjectedThread.ps1  
run the built solution exe with either the argument "caught" or "evade"  
run Get-InjectedThread in powershell and observe the result  
