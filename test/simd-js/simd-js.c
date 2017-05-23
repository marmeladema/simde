/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <test/simd-js/simd-js.h>
#include <simde/simd-js/simd-js.h>

#include <math.h>

static MunitResult
test_simde_em_int32x4_set(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[8] = {
    { { INT32_C( 1686923533), INT32_C( -339399594), INT32_C( 1208422230), INT32_C( 1863337896) },
      { INT32_C( 1686923533), INT32_C( -339399594), INT32_C( 1208422230), INT32_C( 1863337896) } },
    { { INT32_C(  921619215), INT32_C( 1488585756), INT32_C( 1420288323), INT32_C(-1081566784) },
      { INT32_C(  921619215), INT32_C( 1488585756), INT32_C( 1420288323), INT32_C(-1081566784) } },
    { { INT32_C(  842412681), INT32_C( -271480119), INT32_C(-1186702606), INT32_C( 1949472484) },
      { INT32_C(  842412681), INT32_C( -271480119), INT32_C(-1186702606), INT32_C( 1949472484) } },
    { { INT32_C( -479621788), INT32_C(  519644324), INT32_C(  234954023), INT32_C( -954271943) },
      { INT32_C( -479621788), INT32_C(  519644324), INT32_C(  234954023), INT32_C( -954271943) } },
    { { INT32_C( 1854916977), INT32_C(-1817496280), INT32_C(  371629665), INT32_C(  584223329) },
      { INT32_C( 1854916977), INT32_C(-1817496280), INT32_C(  371629665), INT32_C(  584223329) } },
    { { INT32_C(-1930420089), INT32_C( 1125994374), INT32_C( 1692020876), INT32_C( -969781295) },
      { INT32_C(-1930420089), INT32_C( 1125994374), INT32_C( 1692020876), INT32_C( -969781295) } },
    { { INT32_C( 1629102615), INT32_C( 1060700216), INT32_C(   77198508), INT32_C(-1943787893) },
      { INT32_C( 1629102615), INT32_C( 1060700216), INT32_C(   77198508), INT32_C(-1943787893) } },
    { { INT32_C(-1096411985), INT32_C( 1818939186), INT32_C( 1520107459), INT32_C(-1787952693) },
      { INT32_C(-1096411985), INT32_C( 1818939186), INT32_C( 1520107459), INT32_C(-1787952693) } }
  };

  /* printf("\n"); */
  /* for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) { */
  /*   int32_t a[4]; */
  /*   simde_em_int32x4 r; */

  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */

  /*   r = simde_em_int32x4_set(a[0], a[1], a[2], a[3]); */

  /*   printf("    { { INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ") },\n", */
  /* 	   a[0], a[1], a[2], a[3]); */
  /*   printf("      { INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ") } },\n", */
  /* 	   r.v[0], r.v[1], r.v[2], r.v[3]); */
  /*   /\* printf("      simde_em_int32x4_set(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n", *\/ */
  /*   /\* 	   r.v[0], r.v[1], r.v[2], r.v[3]); *\/ */
  /* } */
  /* return MUNIT_FAIL; */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_set(test_vec[i].a[0], test_vec[i].a[1], test_vec[i].a[2], test_vec[i].a[3]);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_splat(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { INT32_C(  408003717),
      simde_em_int32x4_set(INT32_C(  408003717), INT32_C(  408003717), INT32_C(  408003717), INT32_C(  408003717)) },
    { INT32_C(-1301003433),
      simde_em_int32x4_set(INT32_C(-1301003433), INT32_C(-1301003433), INT32_C(-1301003433), INT32_C(-1301003433)) },
    { INT32_C(-1258097748),
      simde_em_int32x4_set(INT32_C(-1258097748), INT32_C(-1258097748), INT32_C(-1258097748), INT32_C(-1258097748)) },
    { INT32_C( -593002803),
      simde_em_int32x4_set(INT32_C( -593002803), INT32_C( -593002803), INT32_C( -593002803), INT32_C( -593002803)) },
    { INT32_C( -234816804),
      simde_em_int32x4_set(INT32_C( -234816804), INT32_C( -234816804), INT32_C( -234816804), INT32_C( -234816804)) },
    { INT32_C( 2091689241),
      simde_em_int32x4_set(INT32_C( 2091689241), INT32_C( 2091689241), INT32_C( 2091689241), INT32_C( 2091689241)) },
    { INT32_C( -250193710),
      simde_em_int32x4_set(INT32_C( -250193710), INT32_C( -250193710), INT32_C( -250193710), INT32_C( -250193710)) },
    { INT32_C(-2147113257),
      simde_em_int32x4_set(INT32_C(-2147113257), INT32_C(-2147113257), INT32_C(-2147113257), INT32_C(-2147113257)) }
  };

  /* printf("\n"); */
  /* for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) { */
  /*   int32_t a; */
  /*   simde_em_int32x4 r; */

  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */

  /*   r = simde_em_int32x4_splat(a); */

  /*   printf("    { INT32_C(%11" PRId32 "),\n", a); */
  /*   printf("      simde_em_int32x4_set(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n", */
  /*   	   r.v[0], r.v[1], r.v[2], r.v[3]); */
  /* } */
  /* return MUNIT_FAIL; */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_splat(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_add(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(UINT32_C( -130054789), UINT32_C( -401734081), UINT32_C( 1269747402), UINT32_C( -508892901)),
      simde_em_int32x4_set(UINT32_C(  734233905), UINT32_C( -878683482), UINT32_C( 1174096883), UINT32_C(-1544702640)),
      simde_em_int32x4_set(UINT32_C(  604179116), UINT32_C(-1280417563), UINT32_C(-1851123011), UINT32_C(-2053595541)) },
    { simde_em_int32x4_set(UINT32_C( 1788993036), UINT32_C( 2015130024), UINT32_C(-1454134978), UINT32_C( 1814399676)),
      simde_em_int32x4_set(UINT32_C( -657913328), UINT32_C(-1955918330), UINT32_C( 1090706297), UINT32_C( -241091274)),
      simde_em_int32x4_set(UINT32_C( 1131079708), UINT32_C(   59211694), UINT32_C( -363428681), UINT32_C( 1573308402)) },
    { simde_em_int32x4_set(UINT32_C( -133951728), UINT32_C(-1602274563), UINT32_C(  813553307), UINT32_C( -909785972)),
      simde_em_int32x4_set(UINT32_C(  923795685), UINT32_C(  188916954), UINT32_C( 1558620902), UINT32_C( -213941642)),
      simde_em_int32x4_set(UINT32_C(  789843957), UINT32_C(-1413357609), UINT32_C(-1922793087), UINT32_C(-1123727614)) },
    { simde_em_int32x4_set(UINT32_C(   89193042), UINT32_C( 1146928390), UINT32_C(  228884520), UINT32_C( -318784613)),
      simde_em_int32x4_set(UINT32_C( -882737959), UINT32_C(-1087386362), UINT32_C(  647187678), UINT32_C(-1024342776)),
      simde_em_int32x4_set(UINT32_C( -793544917), UINT32_C(   59542028), UINT32_C(  876072198), UINT32_C(-1343127389)) },
    { simde_em_int32x4_set(UINT32_C(-1256057379), UINT32_C(-1986030630), UINT32_C(-1207245357), UINT32_C( -900753160)),
      simde_em_int32x4_set(UINT32_C(  295338101), UINT32_C( 1938958840), UINT32_C( -577851625), UINT32_C(-1964292814)),
      simde_em_int32x4_set(UINT32_C( -960719278), UINT32_C(  -47071790), UINT32_C(-1785096982), UINT32_C( 1429921322)) },
    { simde_em_int32x4_set(UINT32_C(-1836674315), UINT32_C(  276208638), UINT32_C( 1208429270), UINT32_C(-2088893437)),
      simde_em_int32x4_set(UINT32_C( -696286550), UINT32_C( 1080546136), UINT32_C( -464480723), UINT32_C( 1763719828)),
      simde_em_int32x4_set(UINT32_C( 1762006431), UINT32_C( 1356754774), UINT32_C(  743948547), UINT32_C( -325173609)) },
    { simde_em_int32x4_set(UINT32_C(-1784409930), UINT32_C(  684654184), UINT32_C(-1809625286), UINT32_C( 1429970648)),
      simde_em_int32x4_set(UINT32_C( 2144186007), UINT32_C( 1898630377), UINT32_C( 1398983174), UINT32_C( -271810807)),
      simde_em_int32x4_set(UINT32_C(  359776077), UINT32_C(-1711682735), UINT32_C( -410642112), UINT32_C( 1158159841)) },
    { simde_em_int32x4_set(UINT32_C( 1191160897), UINT32_C( -508418983), UINT32_C(  685454140), UINT32_C(-1319802529)),
      simde_em_int32x4_set(UINT32_C(  957908541), UINT32_C( -382522768), UINT32_C( 2102744472), UINT32_C(-1526513662)),
      simde_em_int32x4_set(UINT32_C(-2145897858), UINT32_C( -890941751), UINT32_C(-1506768684), UINT32_C( 1448651105)) }
  };

  /* printf("\n"); */
  /* for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) { */
  /*   simde_em_int32x4 a, b, r; */

  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */

  /*   r = simde_em_int32x4_add(a, b); */

  /*   printf("    { simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   a.v[0], a.v[1], a.v[2], a.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   b.v[0], b.v[1], b.v[2], b.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)) },\n", */
  /* 	   r.v[0], r.v[1], r.v[2], r.v[3]); */
  /* } */
  /* return MUNIT_FAIL; */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_add(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_sub(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(UINT32_C( 1171034757), UINT32_C( 1301599556), UINT32_C(-1899411024), UINT32_C(    1895820)),
      simde_em_int32x4_set(UINT32_C( 1452423188), UINT32_C(-1873896616), UINT32_C(  219225954), UINT32_C(-1496571263)),
      simde_em_int32x4_set(UINT32_C( -281388431), UINT32_C(-1119471124), UINT32_C(-2118636978), UINT32_C( 1498467083)) },
    { simde_em_int32x4_set(UINT32_C(-1892767265), UINT32_C( -758835286), UINT32_C(-1965424001), UINT32_C( 1186393509)),
      simde_em_int32x4_set(UINT32_C(  930412480), UINT32_C(-1507141936), UINT32_C( 1371803635), UINT32_C(  856145635)),
      simde_em_int32x4_set(UINT32_C( 1471787551), UINT32_C(  748306650), UINT32_C(  957739660), UINT32_C(  330247874)) },
    { simde_em_int32x4_set(UINT32_C( -872156952), UINT32_C(-1413825413), UINT32_C( 2007885730), UINT32_C( -395381350)),
      simde_em_int32x4_set(UINT32_C( 1411707706), UINT32_C(   72463335), UINT32_C( -730931721), UINT32_C( 2059992351)),
      simde_em_int32x4_set(UINT32_C( 2011102638), UINT32_C(-1486288748), UINT32_C(-1556149845), UINT32_C( 1839593595)) },
    { simde_em_int32x4_set(UINT32_C( 2115626144), UINT32_C( -315360303), UINT32_C(   38470968), UINT32_C( -280023022)),
      simde_em_int32x4_set(UINT32_C(-1871186200), UINT32_C( 2047425728), UINT32_C(-2020529665), UINT32_C( -923560291)),
      simde_em_int32x4_set(UINT32_C( -308154952), UINT32_C( 1932181265), UINT32_C( 2059000633), UINT32_C(  643537269)) },
    { simde_em_int32x4_set(UINT32_C(  303010912), UINT32_C( 1573848957), UINT32_C(   53143155), UINT32_C( -984600909)),
      simde_em_int32x4_set(UINT32_C(  516264231), UINT32_C(-1828880590), UINT32_C( 1670486809), UINT32_C( 1856062973)),
      simde_em_int32x4_set(UINT32_C( -213253319), UINT32_C( -892237749), UINT32_C(-1617343654), UINT32_C( 1454303414)) },
    { simde_em_int32x4_set(UINT32_C( -879119083), UINT32_C(-1163095336), UINT32_C(  655734221), UINT32_C( 1270016985)),
      simde_em_int32x4_set(UINT32_C(  125997037), UINT32_C( -102393225), UINT32_C( 2055351476), UINT32_C( 1591598034)),
      simde_em_int32x4_set(UINT32_C(-1005116120), UINT32_C(-1060702111), UINT32_C(-1399617255), UINT32_C( -321581049)) },
    { simde_em_int32x4_set(UINT32_C(-1955519684), UINT32_C(  526101249), UINT32_C(-2004258965), UINT32_C(  981184505)),
      simde_em_int32x4_set(UINT32_C(  -55197038), UINT32_C( -158449914), UINT32_C( 1299340339), UINT32_C( 1757148687)),
      simde_em_int32x4_set(UINT32_C(-1900322646), UINT32_C(  684551163), UINT32_C(  991367992), UINT32_C( -775964182)) },
    { simde_em_int32x4_set(UINT32_C(-1972837826), UINT32_C( 1806252159), UINT32_C(  847393469), UINT32_C(  848361403)),
      simde_em_int32x4_set(UINT32_C(  849648236), UINT32_C( -893962239), UINT32_C( 1364936275), UINT32_C( -971361447)),
      simde_em_int32x4_set(UINT32_C( 1472481234), UINT32_C(-1594752898), UINT32_C( -517542806), UINT32_C( 1819722850)) }
  };

  /* printf("\n"); */
  /* for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) { */
  /*   simde_em_int32x4 a, b, r; */

  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */

  /*   r = simde_em_int32x4_sub(a, b); */

  /*   printf("    { simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   a.v[0], a.v[1], a.v[2], a.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   b.v[0], b.v[1], b.v[2], b.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)) },\n", */
  /* 	   r.v[0], r.v[1], r.v[2], r.v[3]); */
  /* } */
  /* return MUNIT_FAIL; */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_sub(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_mul(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(UINT32_C(-1560811561), UINT32_C(-1403083270), UINT32_C(     494198), UINT32_C(-1161358910)),
      simde_em_int32x4_set(UINT32_C(-2114570857), UINT32_C(  -99146865), UINT32_C( -119795904), UINT32_C( -293405313)),
      simde_em_int32x4_set(UINT32_C(-1831648559), UINT32_C( 1191568550), UINT32_C(-1066956928), UINT32_C( -976058050)) },
    { simde_em_int32x4_set(UINT32_C(-1946618876), UINT32_C( -993132571), UINT32_C(-1534046454), UINT32_C(-1179602562)),
      simde_em_int32x4_set(UINT32_C(-1502836051), UINT32_C(-1946906427), UINT32_C( -267806115), UINT32_C( 1979587286)),
      simde_em_int32x4_set(UINT32_C( 1417088692), UINT32_C(-1883587783), UINT32_C(-1085097310), UINT32_C( -591451308)) },
    { simde_em_int32x4_set(UINT32_C(-1173967818), UINT32_C( -652266151), UINT32_C( 1875904741), UINT32_C(-1827831069)),
      simde_em_int32x4_set(UINT32_C(  -43629496), UINT32_C(-1465843629), UINT32_C( -335477536), UINT32_C( -534402209)),
      simde_em_int32x4_set(UINT32_C(  321046320), UINT32_C( 1511476187), UINT32_C(  990927968), UINT32_C(  591409981)) },
    { simde_em_int32x4_set(UINT32_C(  349032241), UINT32_C( -998863186), UINT32_C( 2113943593), UINT32_C(-1176290458)),
      simde_em_int32x4_set(UINT32_C( 1172132624), UINT32_C( 1693117938), UINT32_C(  808440034), UINT32_C( -892383455)),
      simde_em_int32x4_set(UINT32_C(  425121296), UINT32_C( -583666052), UINT32_C( 1767498802), UINT32_C(-1726406106)) },
    { simde_em_int32x4_set(UINT32_C(-1116214467), UINT32_C(-1007081170), UINT32_C( 1661319406), UINT32_C(   18487980)),
      simde_em_int32x4_set(UINT32_C( -933286115), UINT32_C( -603665234), UINT32_C(  160922604), UINT32_C( -475426202)),
      simde_em_int32x4_set(UINT32_C( 1852365033), UINT32_C( -320690876), UINT32_C( 2072171880), UINT32_C( 1932048520)) },
    { simde_em_int32x4_set(UINT32_C(-1072914281), UINT32_C( 1140050996), UINT32_C(-2099106205), UINT32_C(-1549697967)),
      simde_em_int32x4_set(UINT32_C(  175366662), UINT32_C(  724985897), UINT32_C( -777257858), UINT32_C(  586122419)),
      simde_em_int32x4_set(UINT32_C(-1343876726), UINT32_C(-1141320620), UINT32_C( -534951750), UINT32_C( 2141368483)) },
    { simde_em_int32x4_set(UINT32_C( 1951386016), UINT32_C( -773957576), UINT32_C( 1446631235), UINT32_C(-1582286610)),
      simde_em_int32x4_set(UINT32_C( -301501293), UINT32_C(   76332231), UINT32_C( -581420062), UINT32_C( 1682294414)),
      simde_em_int32x4_set(UINT32_C(  881673952), UINT32_C(-1958759544), UINT32_C( 1236564518), UINT32_C( 1273866244)) },
    { simde_em_int32x4_set(UINT32_C(-2017022165), UINT32_C(-1150642358), UINT32_C(  442182040), UINT32_C(  705579870)),
      simde_em_int32x4_set(UINT32_C(  302298485), UINT32_C(-2012578749), UINT32_C(  -21687377), UINT32_C( -433670233)),
      simde_em_int32x4_set(UINT32_C( 1246983591), UINT32_C( -418287522), UINT32_C(   14661352), UINT32_C( 1260870738)) }
  };

  /* printf("\n"); */
  /* for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) { */
  /*   simde_em_int32x4 a, b, r; */

  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */

  /*   r = simde_em_int32x4_mul(a, b); */

  /*   printf("    { simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   a.v[0], a.v[1], a.v[2], a.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)),\n", */
  /* 	   b.v[0], b.v[1], b.v[2], b.v[3]); */
  /*   printf("      simde_em_int32x4_set(UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d), UINT32_C(%11d)) },\n", */
  /* 	   r.v[0], r.v[1], r.v[2], r.v[3]); */
  /* } */
  /* return MUNIT_FAIL; */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_mul(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(em_int32x4_set),
  TEST_FUNC(em_int32x4_splat),
  TEST_FUNC(em_int32x4_add),
  TEST_FUNC(em_int32x4_sub),
  TEST_FUNC(em_int32x4_mul),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_simd_js_test_suite simde_simd_js_emul_test_suite
#endif

MunitSuite simde_simd_js_test_suite = {
  (char*) "",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
