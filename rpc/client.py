import xmlrpc.client


def main():
    proxy = xmlrpc.client.ServerProxy("http://localhost:8000/RPC2")

    x = int(input("Enter first Number : "))
    y = int(input("Enter second Number : "))

    result_add =proxy.add(x,y)
    result_subtract = proxy.subtract(x,y)

    print(f"Addition result : {result_add}")
    print(f"Subtraction result : {result_subtract}")



if __name__ =="__main__":
   main()

