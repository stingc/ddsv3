echo %1
runas /user:administrator "netsh http add urlacl url=%1 user=foxera\13790 listen=yes"
