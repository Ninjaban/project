if [ -f /etc/md5sums.md5 ];
then
	RES=$(md5sum -c /etc/md5sums.md5)

	if [ "$RES"=="/etc/crontab: OK" ];
	then
		echo "OK"
	else
		echo "file /etc/crontab modified" | mail -s "CRONTAB MODIFIED" root@debian
	fi
else
	echo "Crontab md5 reference $FILE has been deleted" | mail -s "CRONTAB MD5 REFERENCE" root@debian
fi
