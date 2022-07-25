
// miniNFS

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "mininfs_server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>

// ecs251
#include "Core.h"
#include "Directory.h"
#include "Shadow_Directory.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

class Mymininfs_Server : public mininfs_Server
{
public:
  Mymininfs_Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value UpdateFile(const std::string& action, const std::string& arguments, const std::string& class_id, const std::string& created_class_id, const std::string& fhandle, const std::string& filename, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& sattr, const std::string& newFile_fhandle, const std::string& newFile_filename);
  virtual Json::Value LookUp(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID);
  virtual Json::Value send(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID);
  virtual Json::Value Create(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &created_class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID, const std::string &sattr);
  virtual Json::Value dumpJ(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID);
  virtual Json::Value Zip(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID, const std::string &arg_filetype, const std::string &arg_filesize);
};

Mymininfs_Server::Mymininfs_Server(AbstractServerConnector &connector, serverVersion_t type)
    : mininfs_Server(connector, type)
{
  std::cout << "Mymininfs_Server Object created" << std::endl;
}

Directory *mounted;

// member function

Json::Value
Mymininfs_Server::LookUp(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Receiving LookUp" << std::endl;

  if (fhandle != "00000002") // inode 2 is the root
  {
    result["status"] = "NFSERR_STALE";
  }
  else
  {
    result = mounted->LookUp(fhandle, filename);
  }

  return result;
}

// New Send Function
Json::Value
Mymininfs_Server::send(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Sending Files" << std::endl;

  if (fhandle != "00000002") // inode 2 is the root
  {
    result["status"] = "NFSERR_STALE";
  }
  else
  {
    result = mounted->send(fhandle, filename);
  }

  return result;
}

Json::Value
Mymininfs_Server::Zip(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID, const std::string &arg_filetype, const std::string &arg_filesize)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Calling Zip" << std::endl;

  if (fhandle != "00000002") // inode 2 is the root
  {
    result["status"] = "NFSERR_STALE";
  }
  else
  {
    result = mounted->Zip(fhandle, filename, arg_filetype, arg_filesize);
  }

  return result;
}

Json::Value
Mymininfs_Server::UpdateFile(const std::string& action, const std::string& arguments, const std::string& class_id, const std::string& created_class_id, const std::string& fhandle, const std::string& filename, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& sattr, const std::string& newFile_fhandle, const std::string& newFile_filename)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Receiving UpdateFile" << std::endl;

  if (fhandle != "00000002")
    {
      result["status"] = "NFSERR_STALE";
    }
  else
    {
      result = mounted->UpdateFile(fhandle, filename, sattr, newFile_fhandle, newFile_filename);
    }
  
  return result;
}


Json::Value
Mymininfs_Server::Create(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &created_class_id, const std::string &fhandle, const std::string &filename, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID, const std::string &sattr)

{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Receiving Create" << std::endl;

  if (fhandle != "00000002")
  {
    result["status"] = "NFSERR_STALE";
  }
  else
  {
    result = mounted->Create(fhandle, filename, sattr);
  }

  return result;
}

Json::Value
Mymininfs_Server::dumpJ(const std::string &action, const std::string &arguments, const std::string &class_id, const std::string &host_url, const std::string &object_id, const std::string &owner_vsID)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;

  std::cout << "Receiving dumpJ" << std::endl;

  if (object_id != "00000002")
  {
    result["status"] = "NFSERR_STALE";
  }
  else
  {
    Json::Value *myv_ptr = mounted->dumpJ();
    if (myv_ptr != NULL)
    {
      result = *myv_ptr;
      result["status"] = "NFS_OK";
    }
    else
    {
      result["status"] = "NFSERR_STALE";
    }
  }

  return result;
}

int main()
{
  Directory NFS_root{"http://169.237.6.102", "1234567890", "Directory", "00000000", "root", "00000002"};

  mounted = (&NFS_root);

  HttpServer httpserver(8384);
  Mymininfs_Server s(httpserver,
                     JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
