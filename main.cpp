#include <iostream>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

using namespace std;

void init_openssl()
{
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
}

int main(int argc,char* argv[])
{
    BIO* bio;

//    bio = BIO_new_connect("random.org:443");
//    if(bio == NULL)
//    {
//        cout<<"Failed to init bio."<<endl;
//        exit(1);
//    }
//    if(BIO_do_connect(bio) <=0)
//    {
//        cout<<"Failed to connection. Please check hostname & port"<<endl;
//        exit(1);
//    }

//    char buf[] = "GET / HTTP1.1\x0d\x0a";
//    if(BIO_write(bio,buf,sizeof(buf)-1) <=0)
//    {
//        if(!BIO_should_retry(bio))
//        {
//            cout<<"Failed to send!"<<endl;
//        }
//    }

    //SSL_CTX hold the SSLinformation
    SSL_CTX ctx = SSL_CTX_new(SSLv23_client_method());
    SSl ssl;

    bio = BIO_new_ssl_connect(ctx);
    BIO_get_ssl(bio,&ssl);
    SSL_set_mode(ssl,SSL_MODE_AUTO_RETRY);



    return 0;
}
