#include <iostream>
#include <string>

using namespace std;

#define ERROR_LOG(arg...) ;
#define TRACE_LOG(arg...) ;

//把w_103041149_201408, w_103041149_201408_1等形式
// 统一转成w_103041149_201408
string getVirtualAlbumid_wx(unsigned int uin, const string &albumid)
{
	    size_t pos0 = albumid.find("_");
		    if(pos0 == string::npos
					        || pos0 == albumid.size() + 1)
				    {
						        ERROR_LOG("uin:%u, albumid:%s format error",
										            uin, albumid.c_str());
								        return albumid;
										    }
			    size_t pos1 = albumid.find("_", pos0 + 1);
				    if(pos1 == string::npos
							        || pos1 == albumid.size() + 1)
						    {
								        ERROR_LOG("uin:%u, albumid:%s format error",
												            uin, albumid.c_str());
										        return albumid;
												    }
					    size_t pos2 = albumid.find("_", pos1 + 1);
						    if(pos2 == string::npos)
								    {
										        TRACE_LOG("not ex album: uin:%u, albumid:%s",
														            uin, albumid.c_str());
												        return albumid;
														    }
							    else
									    {
											        TRACE_LOG("ex album: uin:%u, albumid:%s",
															            uin, albumid.c_str());
													        return albumid.substr(0, pos2);
															    }
}


//把103041149_201408, 103041149_201408_1等形式
// 统一转成103041149_201408
string getVirtualAlbumid_qq(unsigned int uin, const string &albumid)
{
	    size_t pos1 = albumid.find("_");
		    if(pos1 == string::npos
					        || pos1 == albumid.size() + 1)
				    {
						        ERROR_LOG("uin:%u, albumid:%s format error",
										            uin, albumid.c_str());
								        return albumid;
										    }
			    size_t pos2 = albumid.find("_", pos1 + 1);
				    if(pos2 == string::npos)
						    {
								        TRACE_LOG("not ex album: uin:%u, albumid:%s",
												            uin, albumid.c_str());
										        return albumid;
												    }
					    else
							    {
									        TRACE_LOG("ex album: uin:%u, albumid:%s",
													            uin, albumid.c_str());
											        return albumid.substr(0, pos2);
													    }
}

int main()
{
	string a = "103041149_201408";
	string b = "103041149_201408_13";


	string c = "w_"+a;
	string d = "w_"+b;


	cout<<getVirtualAlbumid_qq(1, a)<<endl;
	cout<<getVirtualAlbumid_qq(1, b)<<endl;

	cout<<getVirtualAlbumid_wx(1, c)<<endl;
	cout<<getVirtualAlbumid_wx(1, d)<<endl;

	return 0;
}

