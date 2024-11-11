from xmlrpc.server  import *

class mathOpearations:
    def add(self,x,y):
        return x+y
    
    def subtract(self,x,y):
        return x-y

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths =('/RPC2',)


def main():
    server = SimpleXMLRPCServer(('localhost',8000),requestHandler=RequestHandler)
    server.register_instance(mathOpearations())
    print("RPC server is listening on port 8000...")
    server.serve_forever()

if __name__ == "__main__":
    main()


