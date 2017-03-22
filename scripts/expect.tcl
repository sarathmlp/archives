#!/usr/bin/expect

set timeout -1

set Machine_IP "172.16.12.150"
set Machine_Passwd "diameter"
set Machine_UsrName "sarath"

set console "sarath#]"

spawn ssh -o UserKnownHostsFile=/dev/null  -o StrictHostKeyChecking=no $Machine_UsrName@$Machine_IP
set spawnssh_sd $spawn_id

set timeout 1
expect -i $spawnssh_sd -re "(yes/no)?"
exp_send -i $spawnssh_sd "yes\r"
set timeout -1

expect -i $spawnssh_sd -re "assword"
exp_send -i $spawnssh_sd "$Machine_Passwd\r"
sleep 1
exp_send -i $spawnssh_sd "export PS1=$console\r"
expect -i $spawnssh_sd -re $console

exp_send -i  $spawnssh_sd "ls /home/sarath > /home/sarath/sarath.log\r"
expect -i $spawnssh_sd -re $console
exp_close -i $spawnssh_sd

spawn scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no $Machine_UsrName@$Machine_IP:/home/sarath/sarath.log .
set spawnssh_sd $spawn_id
exp_send -i $spawnssh_sd "export PS1=$console\r"
expect -i $spawnssh_sd -re "assword"
exp_send -i $spawnssh_sd "$Machine_Passwd\r"
expect -i $spawnssh_sd -re $console
