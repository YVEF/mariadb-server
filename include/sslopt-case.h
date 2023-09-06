#ifndef SSLOPT_CASE_INCLUDED
#define SSLOPT_CASE_INCLUDED

/* Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1335  USA */

#define SSLOPT_CASE_EMBED_MYSQL_SERVER_INTERNAL(prefix)
#define SSLOPT_CASE_EMBED_NOT_WIN32_INTERNAL(prefix)
#define SSLOPT_CASE_EMBED_HAVE_OPENSSL_INTERNAL(prefix)

#if defined(HAVE_OPENSSL) && !defined(EMBEDDED_LIBRARY)
/*
  Include case stmt for the ssl options.
  Note: internal usage. For indirect call only.
*/
#undef SSLOPT_CASE_EMBED_HAVE_OPENSSL_INTERNAL
#define SSLOPT_CASE_EMBED_HAVE_OPENSSL_INTERNAL(prefix) \
    case OPT_SSL_KEY:                                   \
    case OPT_SSL_CERT:                                  \
    case OPT_SSL_CA:                                    \
    case OPT_SSL_CAPATH:                                \
    case OPT_SSL_CIPHER:                                \
    case OPT_SSL_CRL:                                   \
    case OPT_SSL_CRLPATH:                               \
      prefix opt_use_ssl= 1;                            \
    SSLOPT_CASE_EMBED_MYSQL_SERVER_INTERNAL(prefix)     \
    SSLOPT_CASE_EMBED_NOT_WIN32_INTERNAL(prefix)        \
    break;

#if defined(HAVE_WOLFSSL)

#if defined(MYSQL_SERVER)
/* CRL does not work with WolfSSL (server) */
#undef SSLOPT_CASE_EMBED_MYSQL_SERVER_INTERNAL
#define SSLOPT_CASE_EMBED_MYSQL_SERVER_INTERNAL(prefix) \
  prefix opt_ssl_crl= NULL;
#endif

#if !defined(_WIN32) || !defined(LIBMARIADB)
/* CRL_PATH does not work with WolfSSL (server) and GnuTLS (client) */
#undef SSLOPT_CASE_EMBED_NOT_WIN32_INTERNAL
#define SSLOPT_CASE_EMBED_NOT_WIN32_INTERNAL(prefix) \
  prefix opt_ssl_crlpath= NULL;
#endif  /* NOT_WIN32 */
#endif  /* HAVE_WOLFSSL */
#endif  /* HAVE_OPENSSL */

#endif  /* SSLOPT_CASE_INCLUDED */

#if !defined(SSL_VARS_STATIC) && !defined(SSL_VARS_NON_STATIC)
/*
  Enable use of SSL if we are using any ssl option
  One can disable SSL later by using --skip-ssl or --ssl=0
*/
#define SSLOPT_CASE_EMBED(opts_varname) SSLOPT_CASE_EMBED_HAVE_OPENSSL_INTERNAL(opts_varname.)
#else
#define SSLOPT_CASE_EMPTY_PLACEHOLDER
/* Capture ssl variables to enable use of SSL */
#define SSLOPT_CASE_EMBED_VARS SSLOPT_CASE_EMBED_HAVE_OPENSSL_INTERNAL(SSLOPT_CASE_EMPTY_PLACEHOLDER)
#endif

