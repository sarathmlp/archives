VAR=`cat capwapac_wtp_sess_sm.smil | grep "state name" | grep "transient='false'" | cut -d \' -f 2`
STRING="<transition name='STR1_TO_END'                    from='STR1' to='S_END' on='EV_DTLS_HWSESSION_FAILURE' do='terminate_session'/>"
echo $VAR
for i in $VAR;
do
    echo $STRING | sed "s/STR1/$i/g"
done
