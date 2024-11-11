import ntplib
from time import  ctime, time

def  get_ntp_time(server ="pool.ntp.org"):
    try:
        local_time = time()
        print("Local System Time :",ctime(local_time))

        client = ntplib.NTPClient()
        response = client.request(server,version = 3)


        ntp_time = response.tx_time
        offset = response.offset

        print("Synchronized  NTP Time :",ctime(ntp_time))
        print("Offset(seconds) :",offset)

        return ntp_time,offset
    
    except Exception as e:
        print("Could not synchronize with NTP server : ",e)
        return None,None
    

if __name__ == "__main__":
    get_ntp_time()
        