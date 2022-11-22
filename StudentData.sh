#!/bin/bash

#create a record
create_record(){
if [-e Student.txt ]
then
    echo "Student Data File is already exists !!!"
    echo
else
    touch Student.txt
    echo "Student data file created successfully !!!"
    echo
fi
}

#insert records
insert_record(){
while true
do
echo "Enter Student Record"
echo
echo "STUDENT NAME     ||        STUDENT ID       ||      STUDENT EMAIL"
read name
if ["$name"=="q"]
then
       echo "Quitting..."
       break
       echo
else
      echo $name>>Student.txt
      echo "Record inserted successfully!!"
      echo
fi
done
}

#display record
display_record(){
if [!-e Student.txt]
then
      echo "Student file not found"
      echo
else
      echo "STUDENT NAME     ||        STUDENT ID       ||      STUDENT EMAIL"
      cat addressbook.txt
      echo
fi
}

#search record
search_record()
{
read -p "Enter File name : " filename
read -p "Enter record to search :  " record
if [-f "$filename"]
then
result=$(grep -i "$record" "$filename")

if [$result]
then
     echo "$result"
     echo "Record found successfully !!!"
     echo
else
    echo "Record not found"
    echo
fi
}

#delete record
delete_record(){
read -p "Enter record to  delete : " rec
if [$rec]
then
       cat Student.txt | grep -v "$rec" > Student.txt
      echo "Record deleted successfully !"
      echo 
fi
}

echo "Welcome to Student Book"
echo "*******************************************"

while true
do
      echo "1.Create Record"
      echo "2.Insert Record"
      echo "3.Display Record"
      echo "4.Search Record"
      echo "5.Delete Record"
      echo "--------------------------------------"
      echo "Enter your choice"
     read choice

     if [ "$choice"  == "1" ]
    then
         create_record

    elif [$choice==2]
    then
         insert_record

    elif [$choice==3]
    then
         display_record

    elif [$choice==4]
    then
        search_record

     elif [$choice==5]
     then
         delete_record

     elif [$choice==6]
     then 
        break

fi
done
