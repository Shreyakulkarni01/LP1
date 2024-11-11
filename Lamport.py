class LamportClock:
    def __init__(self,process_id):
        self.clock = 0
        self.process_id = process_id

    def local_event(self):
        self.clock+=1
        print(f"Process {self.process_id} - Local event | Clock:{self.clock}")


    def send_event(self):
        self.clock+=1
        print(f"Process {self.process_id} - Send event  | Clock :{self.clock}")
        return self.clock

    def receive_event(self,sender_clock):
        self.clock = max(self.clock,sender_clock) +1
        print(f"Process {self.process_id} - Receive event  | Clock :{self.clock}")


if __name__ == "__main__":
    process_A = LamportClock(process_id ="A")
    process_B = LamportClock(process_id="B")

    process_A.local_event()
    clock_A = process_A.send_event()
    process_B.receive_event(clock_A)

    process_B.local_event()
    clock_B = process_B.send_event()
    process_A.receive_event(clock_B)