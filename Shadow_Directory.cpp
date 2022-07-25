
#include "Shadow_Directory.h"

// JSON RPC part
#include <stdlib.h>
#include "mininfs_client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

Shadow_Directory::Shadow_Directory(std::string arg_host_url, std::string arg_vsID, std::string arg_class_id,
                                   std::string arg_object_id)
    : Directory{arg_host_url, arg_vsID, arg_class_id, arg_object_id}
{
  std::cout << "Shadow created" << std::endl;
}

Json::Value
Shadow_Directory::LookUp(std::string arg_dir_fhandle, std::string arg_name)
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try
  {
    std::cout << "calling NFS LookUp" << std::endl;

    myv = myClient.LookUp("LookUp", "This is a Directory JSON string!",
                          (this->class_id).c_str(), arg_dir_fhandle, arg_name,
                          (this->host_url).c_str(),
                          (this->object_id).c_str(), (this->owner_vsID).c_str());
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  return myv;
}

// Creating the send shadow function
Json::Value
Shadow_Directory::send(std::string arg_dir_fhandle, std::string arg_name)
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try
  {
    std::cout << "Sending Files" << std::endl;

    myv = myClient.send("Send", "This is a Directory JSON string!",
                        (this->class_id).c_str(), arg_dir_fhandle, arg_name,
                        (this->host_url).c_str(),
                        (this->object_id).c_str(), (this->owner_vsID).c_str());
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  return myv;
}


Json::Value
Shadow_Directory::UpdateFile
(std::string arg_dir_fhandle, std::string arg_name, std::string arg_sattr, std::string newFile_fhandle, std::string newFile_filename)
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try {
    std::cout << "calling NFS UpdateFile" << std::endl;

    myv = myClient.UpdateFile("UpdateFile", "This is a Directory JSON string!",
			  (this->class_id).c_str(), std::string {"Node"},
			  arg_dir_fhandle, arg_name,
			  (this->host_url).c_str(),
			  (this->object_id).c_str(), (this->owner_vsID).c_str(),
			  arg_sattr, newFile_fhandle, newFile_filename);
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  return myv;
}


Json::Value
Shadow_Directory::Zip(std::string arg_dir_fhandle, std::string arg_name, std::string arg_filetype, std::string arg_filesize)
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try
  {
    std::cout << "calling NFS Zip" << std::endl;

    myv = myClient.Zip("Zip", "This is a Directory JSON string!",
                       (this->class_id).c_str(), arg_dir_fhandle, arg_name,
                       (this->host_url).c_str(),
                       (this->object_id).c_str(), (this->owner_vsID).c_str(), arg_filetype, arg_filesize);
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  return myv;
}

Json::Value
Shadow_Directory::Create(std::string arg_dir_fhandle, std::string arg_name, std::string arg_sattr)
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try
  {
    std::cout << "calling NFS Create" << std::endl;

    myv = myClient.Create("Create", "This is a Directory JSON string!",
                          (this->class_id).c_str(), std::string{"Node"},
                          arg_dir_fhandle, arg_name,
                          (this->host_url).c_str(),
                          (this->object_id).c_str(), (this->owner_vsID).c_str(),
                          arg_sattr);
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }
  return myv;
}

Json::Value *
Shadow_Directory::dumpJ()
{
  HttpClient httpclient((this->host_url).c_str());
  mininfs_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try
  {
    std::cout << "calling NFS dumpJ" << std::endl;

    myv = myClient.dumpJ("dumpJ", "This is a Directory JSON string!",
                         (this->class_id).c_str(), (this->host_url).c_str(),
                         (this->object_id).c_str(), (this->owner_vsID).c_str());
    cout << myv.toStyledString() << endl;
  }
  catch (JsonRpcException &e)
  {
    cerr << e.what() << endl;
  }

  Json::Value *myv_ptr = new Json::Value();
  (*myv_ptr) = myv;
  return myv_ptr;
}

bool Shadow_Directory::Jdump(Json::Value *mjv_ptr)
{
  return false;
}
