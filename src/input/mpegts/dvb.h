/*
 *  Tvheadend - DVB support routines and defines
 *  Copyright (C) 2007 Andreas �man
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * Based on:
 *
 * ITU-T Recommendation H.222.0 / ISO standard 13818-1
 * EN 300 468 - V1.7.1
 */

#ifndef __TVH_DVB_SUPPORT_H__
#define __TVH_DVB_SUPPORT_H__

struct mpegts_table;
struct mpegts_table_state;
struct mpegts_mux;

/* PIDs */

#define DVB_PAT_PID                   0x00
#define DVB_CAT_PID                   0x01
#define DVB_NIT_PID                   0x10
#define DVB_SDT_PID                   0x11
#define DVB_BAT_PID                   0x11
#define DVB_VCT_PID                   0x1FFB
#define DVB_ATSC_STT_PID              0x1FFB
#define DVB_ATSC_MGT_PID              0x1FFB

/* Tables */

#define DVB_PAT_BASE                  0x00
#define DVB_PAT_MASK                  0x00

#define DVB_CAT_BASE                  0x01
#define DVB_CAT_MASK                  0xFF

#define DVB_PMT_BASE                  0x02
#define DVB_PMT_MASK                  0xFF

#define DVB_NIT_BASE                  0x00
#define DVB_NIT_MASK                  0x00

#define DVB_SDT_BASE                  0x40
#define DVB_SDT_MASK                  0xF8

#define DVB_BAT_BASE                  0x48
#define DVB_BAT_MASK                  0xF8

#define DVB_FASTSCAN_NIT_BASE         0xBC
#define DVB_FASTSCAN_SDT_BASE         0xBD
#define DVB_FASTSCAN_MASK             0xFF

#define DVB_VCT_T_BASE                0xC8
#define DVB_VCT_C_BASE                0xC9
#define DVB_VCT_MASK                  0xFF

#define DVB_ATSC_MGT_BASE             0xC7
#define DVB_ATSC_MGT_MASK             0xFF

#define DVB_ATSC_EIT_BASE             0xCB
#define DVB_ATSC_EIT_MASK             0xFF

#define DVB_ATSC_ETT_BASE             0xCC
#define DVB_ATSC_ETT_MASK             0xFF

#define DVB_ATSC_STT_BASE             0xCD
#define DVB_ATSC_STT_MASK             0xFF

#define DVB_TELETEXT_BASE             0x2000

/* Descriptors */

#define DVB_DESC_VIDEO_STREAM         0x02
#define DVB_DESC_REGISTRATION         0x05
#define DVB_DESC_CA                   0x09
#define DVB_DESC_LANGUAGE             0x0A

/* Descriptors defined in EN 300 468 */

#define DVB_DESC_NETWORK_NAME         0x40
#define DVB_DESC_SERVICE_LIST         0x41
#define DVB_DESC_STUFFING             0x42
#define DVB_DESC_SAT_DEL              0x43
#define DVB_DESC_CABLE_DEL            0x44
#define DVB_DESC_VBI_DATA             0x45
#define DVB_DESC_VBI_TELETEXT         0x46
#define DVB_DESC_BOUQUET_NAME         0x47
#define DVB_DESC_SERVICE              0x48
#define DVB_DESC_COUNTRY_AVAILABILITY 0x49
#define DVB_DESC_LINKAGE              0x4A
#define DVB_DESC_NVOD_REFERENCE       0x4B
#define DVB_DESC_TIME_SHIFTED_SERVICE 0x4C
#define DVB_DESC_SHORT_EVENT          0x4D
#define DVB_DESC_EXT_EVENT            0x4E
#define DVB_DESC_TIME_SHIFTED_EVENT   0x4F
#define DVB_DESC_COMPONENT            0x50
#define DVB_DESC_MOSAIC               0x51
#define DVB_DESC_STREAM_ID            0x52
#define DVB_DESC_CA_ID                0x53
#define DVB_DESC_CONTENT              0x54
#define DVB_DESC_PARENTAL_RAT         0x55
#define DVB_DESC_TELETEXT             0x56
#define DVB_DESC_TELEPHONE            0x57
#define DVB_DESC_LOCAL_TIME_OFFSET    0x58
#define DVB_DESC_SUBTITLE             0x59
#define DVB_DESC_TERR_DEL             0x5A
#define DVB_DESC_MULTI_NETWORK_NAME   0x5B
#define DVB_DESC_MULTI_BOUQUET_NAME   0x5C
#define DVB_DESC_MULTI_SERVICE_NAME   0x5D
#define DVB_DESC_MULTI_COMPONENT_NAME 0x5E
#define DVB_DESC_PRIVATE_DATA         0x5F
#define DVB_DESC_SERVICE_MOVE         0x60
#define DVB_DESC_SHORT_SMOOTHING_BUF  0x61
#define DVB_DESC_FREQ_LIST            0x62
#define DVB_DESC_PARTIAL_TRANSPORT_STREAM 0x63
#define DVB_DESC_DATA_BROADCAST       0x64
#define DVB_DESC_SCRAMBLING           0x65
#define DVB_DESC_DATA_BROADCAST_ID    0x66
#define DVB_DESC_TRANSPORT_STREAM     0x67
#define DVB_DESC_DSNG                 0x68
#define DVB_DESC_PDC                  0x69
#define DVB_DESC_AC3                  0x6A
#define DVB_DESC_ANCILLARY_DATA       0x6B
#define DVB_DESC_CALL_LIST            0x6C
#define DVB_DESC_CALL_FREQ_LINK       0x6D
#define DVB_DESC_ANNOUNCEMENT_SUPPORT 0x6E
#define DVB_DESC_DEF_AUTHORITY        0x73
#define DVB_DESC_CRID                 0x76
#define DVB_DESC_EAC3                 0x7A
#define DVB_DESC_AAC                  0x7C

#define DVB_DESC_BSKYB_LCN            0xB1

#define DVB_DESC_BSKYB_NVOD           0xC0

#define DVB_DESC_FREESAT_LCN          0xD3
#define DVB_DESC_FREESAT_REGIONS      0xD4

/* Descriptors defined in A/65:2009 */

#define ATSC_DESC_STUFFING            0x80
#define ATSC_DESC_AC3                 0x81
#define ATSC_DESC_CAPTION             0x86
#define ATSC_DESC_CONTENT_ADVISORY    0x87
#define ATSC_DESC_EXT_CHANNEL_NAME    0xA0
#define ATSC_DESC_SERVICE_LOCATION    0xA1
#define ATSC_DESC_TIMESHIFTED_SVC     0xA2
#define ATSC_DESC_COMPONENT_NAME      0xA3
#define ATSC_DESC_DCC_DEPARTING       0xA8
#define ATSC_DESC_DCC_ARRIVING        0xA9
#define ATSC_DESC_REDISTRIB_CTRL      0xAA
#define ATSC_DESC_GENRE               0xAB
#define ATSC_DESC_PRIVATE_INFO        0xAD

/* Service type lookup */

int dvb_servicetype_lookup ( int t );

/* String Extraction */

typedef struct dvb_string_conv
{
  uint8_t type;
  size_t  (*func) ( char *dst, size_t *dstlen,
                    const uint8_t* src, size_t srclen );
} dvb_string_conv_t;

int dvb_get_string
  (char *dst, size_t dstlen, const uint8_t *src, const size_t srclen,
   const char *dvb_charset, dvb_string_conv_t *conv);

int dvb_get_string_with_len
  (char *dst, size_t dstlen, const uint8_t *buf, size_t buflen,
   const char *dvb_charset, dvb_string_conv_t *conv);

int atsc_get_string
  (char *dst, size_t dstlen, const uint8_t *src, size_t srclen,
   const char *lang);

/* Conversion */

#define bcdtoint(i) ((((i & 0xf0) >> 4) * 10) + (i & 0x0f))

time_t dvb_convert_date(const uint8_t *dvb_buf);
time_t atsc_convert_gpstime(uint32_t gpstime);
void atsc_utf16_to_utf8(const uint8_t *src, int len, char *buf, int buflen);

/*
 * PSI processing
 */

#define DVB_LOOP_INIT(ptr, len, off, lptr, llen)\
do {\
  llen = ((ptr[off] & 0xF) << 8) | ptr[off+1];\
  lptr = 2 + off + ptr;\
  ptr += 2 + off + llen;\
  len -= 2 + off + llen;\
  if (len < 0) {tvhtrace("psi", "len < 0"); return -1; }\
} while(0)

#define DVB_LOOP_EACH(ptr, len, min)\
  for ( ; len > min ; )\

#define DVB_LOOP_FOREACH(ptr, len, off, lptr, llen, min)\
  DVB_LOOP_INIT(ptr, len, off, lptr, llen);\
  DVB_LOOP_EACH(lptr, llen, min)

#define DVB_DESC_EACH(ptr, len, dtag, dlen, dptr)\
  DVB_LOOP_EACH(ptr, len, 2)\
    if      (!(dtag  = ptr[0]))      {tvhtrace("psi", "1");return -1;}\
    else if ((dlen  = ptr[1]) < 0)   {tvhtrace("psi", "2");return -1;}\
    else if (!(dptr  = ptr+2))       {tvhtrace("psi", "3");return -1;}\
    else if ( (len -= 2 + dlen) < 0) {tvhtrace("psi", "4");return -1;}\
    else if (!(ptr += 2 + dlen))     {tvhtrace("psi", "5");return -1;}\
    else

#define DVB_DESC_FOREACH(ptr, len, off, lptr, llen, dtag, dlen, dptr)\
  DVB_LOOP_INIT(ptr, len, off, lptr, llen);\
  DVB_DESC_EACH(lptr, llen, dtag, dlen, dptr)\

/* PSI table callbacks */

int dvb_table_end
  (struct mpegts_table *mt, struct mpegts_table_state *st, int sect );
int dvb_table_begin
  (struct mpegts_table *mt, const uint8_t *ptr, int len,
   int tableid, uint64_t extraid, int minlen,
   struct mpegts_table_state **st, int *sect, int *last, int *ver);
void dvb_table_reset
  (struct mpegts_table *mt);
void dvb_bat_destroy
  (struct mpegts_table *mt);

int dvb_pat_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_cat_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_pmt_callback  
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tabelid);
int dvb_nit_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_bat_callback  
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_fs_sdt_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_sdt_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int dvb_tdt_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int atsc_vct_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);
int atsc_stt_callback
  (struct mpegts_table *mt, const uint8_t *ptr, int len, int tableid);

void psi_tables_default ( struct mpegts_mux *mm );
void psi_tables_dvb     ( struct mpegts_mux *mm );
void psi_tables_atsc_t  ( struct mpegts_mux *mm );
void psi_tables_atsc_c  ( struct mpegts_mux *mm );

/*
 *
 */
#if ENABLE_MPEGTS_DVB

typedef enum dvb_fe_type {
  DVB_TYPE_NONE = 0,
  DVB_TYPE_T = 1,		/* terrestrial */
  DVB_TYPE_C,			/* cable */
  DVB_TYPE_S,			/* satellite */
  DVB_TYPE_ATSC,		/* terrestrial - north america */
  DVB_TYPE_LAST = DVB_TYPE_ATSC
} dvb_fe_type_t;

typedef enum dvb_fe_delivery_system {
  DVB_SYS_NONE            =    0,
  DVB_SYS_DVBC_ANNEX_A    =  100,
  DVB_SYS_DVBC_ANNEX_B,
  DVB_SYS_DVBC_ANNEX_C,
  DVB_SYS_DVBT            =  200,
  DVB_SYS_DVBT2,
  DVB_SYS_DVBS            =  300,
  DVB_SYS_DVBS2,
  DVB_SYS_DVBH            =  400,
  DVB_SYS_DSS             =  500,
  DVB_SYS_ISDBT           =  600,
  DVB_SYS_ISDBS,
  DVB_SYS_ISDBC,
  DVB_SYS_ATSC            =  700,
  DVB_SYS_ATSCMH,
  DVB_SYS_DTMB            =  800,
  DVB_SYS_CMMB            =  900,
  DVB_SYS_DAB             = 1000,
  DVB_SYS_TURBO           = 1100,
} dvb_fe_delivery_system_t;

typedef enum dvb_fe_spectral_inversion {
  DVB_INVERSION_UNDEFINED,
  DVB_INVERSION_AUTO,
  DVB_INVERSION_OFF,
  DVB_INVERSION_ON,
} dvb_fe_spectral_inversion_t;

typedef enum dvb_fe_code_rate {
  DVB_FEC_NONE  =    0,
  DVB_FEC_AUTO,
  DVB_FEC_1_2   =  102,
  DVB_FEC_1_3   =  103,
  DVB_FEC_1_5   =  105,
  DVB_FEC_2_3   =  203,
  DVB_FEC_2_5   =  205,
  DVB_FEC_2_9   =  209,
  DVB_FEC_3_4   =  304,
  DVB_FEC_3_5   =  305,
  DVB_FEC_4_5   =  405,
  DVB_FEC_4_15  =  415,
  DVB_FEC_5_6   =  506,
  DVB_FEC_5_9   =  509,
  DVB_FEC_6_7   =  607,
  DVB_FEC_7_8   =  708,
  DVB_FEC_7_9   =  709,
  DVB_FEC_7_15  =  715,
  DVB_FEC_8_9   =  809,
  DVB_FEC_8_15  =  815,
  DVB_FEC_9_10  =  910,
  DVB_FEC_9_20  =  920,
  DVB_FEC_11_15 = 1115,
  DVB_FEC_11_20 = 1120,
  DVB_FEC_11_45 = 1145,
  DVB_FEC_13_18 = 1318,
  DVB_FEC_13_45 = 1345,
  DVB_FEC_14_45 = 1445,
  DVB_FEC_23_36 = 2336,
  DVB_FEC_25_36 = 2536,
  DVB_FEC_26_45 = 2645,
  DVB_FEC_28_45 = 2845,
  DVB_FEC_29_45 = 2945,
  DVB_FEC_31_45 = 3145,
  DVB_FEC_32_45 = 3245,
  DVB_FEC_77_90 = 7790,
} dvb_fe_code_rate_t;

typedef enum dvb_fe_modulation {
  DVB_MOD_NONE       =     0,
  DVB_MOD_AUTO,
  DVB_MOD_QPSK       =  1001,
  DVB_MOD_QAM_4_NR   =  2004,
  DVB_MOD_QAM_AUTO   =  3000,
  DVB_MOD_QAM_16     =  3016,
  DVB_MOD_QAM_32     =  3032,
  DVB_MOD_QAM_64     =  3064,
  DVB_MOD_QAM_128    =  3128,
  DVB_MOD_QAM_256    =  3256,
  DVB_MOD_VSB_8      =  4008,
  DVB_MOD_VSB_16     =  4016,
  DVB_MOD_PSK_8      =  5008,
  DVB_MOD_DQPSK      =  6001,
  DVB_MOD_BPSK       =  7001,
  DVB_MOD_BPSK_S     =  8001,
  DVB_MOD_APSK_16    =  9016,
  DVB_MOD_APSK_32    =  9032,
  DVB_MOD_APSK_64    =  9064,
  DVB_MOD_APSK_128   =  9128,
  DVB_MOD_APSK_256   =  9256,
  DVB_MOD_APSK_8_L   = 10008,
  DVB_MOD_APSK_16_L  = 10016,
  DVB_MOD_APSK_32_L  = 10032,
  DVB_MOD_APSK_64_L  = 10064,
  DVB_MOD_APSK_128_L = 10128,
  DVB_MOD_APSK_256_L = 10256,
} dvb_fe_modulation_t;

typedef enum dvb_fe_transmit_mode {
  DVB_TRANSMISSION_MODE_NONE =      0,
  DVB_TRANSMISSION_MODE_AUTO,
  DVB_TRANSMISSION_MODE_1K    =   100,
  DVB_TRANSMISSION_MODE_2K,
  DVB_TRANSMISSION_MODE_4K,
  DVB_TRANSMISSION_MODE_8K,
  DVB_TRANSMISSION_MODE_16K,
  DVB_TRANSMISSION_MODE_32K,
  DVB_TRANSMISSION_MODE_C1    = 10001,
  DVB_TRANSMISSION_MODE_C3780 = 13780,
} dvb_fe_transmit_mode_t;

typedef enum dvb_fe_bandwidth {
  DVB_BANDWIDTH_NONE          =     0,
  DVB_BANDWIDTH_AUTO,
  DVB_BANDWIDTH_1_712_MHZ     =  1712,
  DVB_BANDWIDTH_5_MHZ         =  5000,
  DVB_BANDWIDTH_6_MHZ         =  6000,
  DVB_BANDWIDTH_7_MHZ         =  7000,
  DVB_BANDWIDTH_8_MHZ         =  8000,
  DVB_BANDWIDTH_10_MHZ        = 10000,
} dvb_fe_bandwidth_t;

typedef enum dvb_fe_guard_interval {
  DVB_GUARD_INTERVAL_NONE =         0,
  DVB_GUARD_INTERVAL_AUTO,
  DVB_GUARD_INTERVAL_1_4      =  1004,
  DVB_GUARD_INTERVAL_1_8      =  1008,
  DVB_GUARD_INTERVAL_1_16     =  1016,
  DVB_GUARD_INTERVAL_1_32     =  1032,
  DVB_GUARD_INTERVAL_1_128    =  1128,
  DVB_GUARD_INTERVAL_19_128   = 19128,
  DVB_GUARD_INTERVAL_19_256   = 19256,
  DVB_GUARD_INTERVAL_PN420    = 90420,
  DVB_GUARD_INTERVAL_PN595    = 90595,
  DVB_GUARD_INTERVAL_PN945    = 90945,
} dvb_fe_guard_interval_t;

typedef enum dvb_fe_hierarchy {
  DVB_HIERARCHY_NONE          =    0,
  DVB_HIERARCHY_AUTO,
  DVB_HIERARCHY_1             = 1001,
  DVB_HIERARCHY_2             = 1002,
  DVB_HIERARCHY_4             = 1004,
} dvb_fe_hierarchy_t;

typedef enum dvb_fe_pilot {
  DVB_PILOT_NONE = 0,
  DVB_PILOT_AUTO,
  DVB_PILOT_ON,
  DVB_PILOT_OFF,
} dvb_fe_pilot_t;

typedef enum dvb_fe_rolloff {
  DVB_ROLLOFF_NONE       =   0,
  DVB_ROLLOFF_AUTO,
  DVB_ROLLOFF_20         = 200,
  DVB_ROLLOFF_25         = 250,
  DVB_ROLLOFF_35         = 350,
} dvb_fe_rolloff_t;

typedef enum dvb_polarisation {
  DVB_POLARISATION_HORIZONTAL     = 0x00,
  DVB_POLARISATION_VERTICAL       = 0x01,
  DVB_POLARISATION_CIRCULAR_LEFT  = 0x02,
  DVB_POLARISATION_CIRCULAR_RIGHT = 0x03,
  DVB_POLARISATION_OFF            = 0x04
} dvb_polarisation_t;

typedef struct dvb_qpsk_config {
  dvb_polarisation_t  polarisation;
  int                 orbital_pos;
  char                orbital_dir;
  uint32_t            symbol_rate;
  dvb_fe_code_rate_t  fec_inner;
} dvb_qpsk_config_t;

typedef struct dvb_qam_config {
  uint32_t            symbol_rate;
  dvb_fe_code_rate_t  fec_inner;
} dvb_qam_config_t;

typedef struct dvb_ofdm_config {
  dvb_fe_bandwidth_t      bandwidth;
  dvb_fe_code_rate_t      code_rate_HP;
  dvb_fe_code_rate_t      code_rate_LP;
  dvb_fe_transmit_mode_t  transmission_mode;
  dvb_fe_guard_interval_t guard_interval;
  dvb_fe_hierarchy_t      hierarchy_information;
} dvb_ofdm_config_t;

typedef struct dvb_mux_conf
{
  dvb_fe_type_t               dmc_fe_type;
  dvb_fe_delivery_system_t    dmc_fe_delsys;
  dvb_fe_modulation_t         dmc_fe_modulation;
  uint32_t                    dmc_fe_freq;
  dvb_fe_spectral_inversion_t dmc_fe_inversion;
  dvb_fe_rolloff_t            dmc_fe_rolloff;
  dvb_fe_pilot_t              dmc_fe_pilot;
  union {
    dvb_qpsk_config_t         dmc_fe_qpsk;
    dvb_qam_config_t          dmc_fe_qam;
    dvb_ofdm_config_t         dmc_fe_ofdm;
  } u;

  // For scan file configurations
  LIST_ENTRY(dvb_mux_conf)    dmc_link;
  
} dvb_mux_conf_t;

/* conversion routines */
const char *dvb_rolloff2str ( int rolloff );
const char *dvb_delsys2str  ( int delsys );
const char *dvb_fec2str     ( int fec );
const char *dvb_qam2str     ( int qam );
const char *dvb_bw2str      ( int bw );
const char *dvb_mode2str    ( int mode );
const char *dvb_inver2str   ( int inver );
const char *dvb_guard2str   ( int guard );
const char *dvb_hier2str    ( int hier );
const char *dvb_pol2str     ( int pol );
const char *dvb_type2str    ( int type );
const char *dvb_pilot2str   ( int pilot );
#define dvb_feclo2str dvb_fec2str
#define dvb_fechi2str dvb_fec2str

int dvb_str2rolloff ( const char *str );
int dvb_str2delsys  ( const char *str );
int dvb_str2fec     ( const char *str );
int dvb_str2qam     ( const char *str );
int dvb_str2bw      ( const char *str );
int dvb_str2inver   ( const char *str );
int dvb_str2mode    ( const char *str );
int dvb_str2guard   ( const char *str );
int dvb_str2hier    ( const char *str );
int dvb_str2pol     ( const char *str );
int dvb_str2type    ( const char *str );
int dvb_str2pilot   ( const char *str );
#define dvb_str2feclo dvb_str2fec
#define dvb_str2fechi dvb_str2fec

static inline int dvb_bandwidth( dvb_fe_bandwidth_t bw )
{
  return bw < 1000 ? 0 : bw * 1000;
}

int dvb_delsys2type ( enum dvb_fe_delivery_system ds );

int dvb_mux_conf_str ( dvb_mux_conf_t *conf, char *buf, size_t bufsize );

int dvb_sat_position( const dvb_mux_conf_t *mc );

const char *dvb_sat_position_to_str( int position, char *buf, size_t buflen );

const int dvb_sat_position_from_str( const char *buf );

#endif /* ENABLE_MPEGTS_DVB */

void dvb_init       ( void );
void dvb_done       ( void );

#endif /* DVB_SUPPORT_H */
