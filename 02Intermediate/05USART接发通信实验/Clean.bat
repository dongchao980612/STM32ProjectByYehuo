
::�򿪻���
@echo on

::ɾ���ļ�
del=/s /a /f "JLinkLog.txt"
del=/s /a /f "*.ini"
del=/s /a /f "*.uvguix.*"
del=/s /a /f "*.uvoptx.*"
del=/s /a /f "*.scvd"

::ɾ�� "DebugConfig" "Listings" "Objects"�ļ���
for /f "delims=" %%i in ('dir /ad /b /s "DebugConfig" "Listings" "Obj" "Objects"') do (
   rd /s /q "%%i"
)

::ɾ�����ļ���
::for /f "tokens=*" %%i in ('dir/s/b/ad^|sort /r') do rd "%%i"

exit