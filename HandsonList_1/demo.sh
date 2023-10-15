#!/bin/bash
add_record(){
	echo "enter Employee Name: "
	read name
	echo "enter Employee Number: "
	read emp_no
	echo "Enter Telphone number: "
	read tel_no

	echo "$name:$emp_no:$tel_no">>employee_record.txt
	echo "employee record added"
}
delete_record(){
	echo "enter employee no. whose record you want deleted"
	read emp_no
	grep -v "^.*:emp_no:*" employee_record.txt >text.txt
	mv text.txt employee_record.txt
	echo "record deleted"
}
search_record(){
	echo "enter emp no. to be searched"
	read emp_no
	grep "^.*:$emp_no:*" employee_record.txt
}
list_record(){
        echo "Records: "
	cat employee_record.txt
}
sort_record(){
	sort -k2 -n employee_record.txt
	echo "sorted"
	cat employee_record.txt
}
while true;
do echo "1.Add Record"
   echo "2. Delete"
   echo "3. Search"
   echo "4.List all"
   echo "5.sort"
   echo "6.exit"

   read choice
   case $choice in
	   1) add_record;;
	   2) delete_record;;
	   3) search_record;;
	   4) list_record;;
	   5) sort_record;;
	   6) exit 0;;
	   *) echo"invalid";;
   esac

done
