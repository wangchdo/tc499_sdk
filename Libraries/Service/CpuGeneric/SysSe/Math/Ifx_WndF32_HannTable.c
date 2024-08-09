/**
 * \file Ifx_WndF32_HannTable.c
 * \brief Lookup table for Hann window function
 *
 *
 * \version iLLD_2_0_1_2_19
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "Ifx_WndF32.h"

#if IFX_WNDF32_TABLE_LENGTH != 1024
#error This was generated with IFX_WNDF32_TABLE_LENGTH = 1024. Please regenerate.
#endif

CONST_CFG float32 Ifx_g_WndF32_hannTable[(IFX_WNDF32_TABLE_LENGTH / 2)] = {
    _DATAF(0.00000000000000000000),
    _DATAF(0.00000943076884141192),
    _DATAF(0.00003772272248170339),
    _DATAF(0.00008487478771712631),
    _DATAF(0.00015088518557604402),
    _DATAF(0.00023575144587084651),
    _DATAF(0.00033947033807635307),
    _DATAF(0.00046203794772736728),
    _DATAF(0.00060344970552250743),
    _DATAF(0.00076370022725313902),
    _DATAF(0.00094278343021869659),
    _DATAF(0.00114069262053817510),
    _DATAF(0.00135742034763097760),
    _DATAF(0.00159295846242457630),
    _DATAF(0.00184729788452386860),
    _DATAF(0.00212042918428778650),
    _DATAF(0.00241234223358333110),
    _DATAF(0.00272302562370896340),
    _DATAF(0.00305246794596314430),
    _DATAF(0.00340065662749111650),
    _DATAF(0.00376757839694619180),
    _DATAF(0.00415321951732039450),
    _DATAF(0.00455756578594446180),
    _DATAF(0.00498060183599591260),
    _DATAF(0.00542231136932969090),
    _DATAF(0.00588267762213945390),
    _DATAF(0.00636168383061885830),
    _DATAF(0.00685931136831641200),
    _DATAF(0.00737554160878062250),
    _DATAF(0.00791035499423742290),
    _DATAF(0.00846373196691274640),
    _DATAF(0.00903565157204866410),
    _DATAF(0.00962609145790338520),
    _DATAF(0.01023502927273511900),
    _DATAF(0.01086244266480207400),
    _DATAF(0.01150830835103988600),
    _DATAF(0.01217260118573904000),
    _DATAF(0.01285529602319002200),
    _DATAF(0.01355636864900589000),
    _DATAF(0.01427579019218683200),
    _DATAF(0.01501353550702333500),
    _DATAF(0.01576957479119300800),
    _DATAF(0.01654388196766376500),
    _DATAF(0.01733642630279064200),
    _DATAF(0.01814717799425125100),
    _DATAF(0.01897610723972320600),
    _DATAF(0.01982318051159381900),
    _DATAF(0.02068836987018585200),
    _DATAF(0.02157163806259632100),
    _DATAF(0.02247295528650283800),
    _DATAF(0.02339228615164756800),
    _DATAF(0.02432959713041782400),
    _DATAF(0.02528485096991062200),
    _DATAF(0.02625801227986812600),
    _DATAF(0.02724904380738735200),
    _DATAF(0.02825791016221046400),
    _DATAF(0.02928457222878933000),
    _DATAF(0.03032899089157581300),
    _DATAF(0.03139112517237663300),
    _DATAF(0.03247094154357910200),
    _DATAF(0.03356838971376419100),
    _DATAF(0.03468343615531921400),
    _DATAF(0.03581603243947029100),
    _DATAF(0.03696614131331443800),
    _DATAF(0.03813371807336807300),
    _DATAF(0.03931871801614761400),
    _DATAF(0.04052109271287918100),
    _DATAF(0.04174080491065979000),
    _DATAF(0.04297780245542526200),
    _DATAF(0.04423204064369201700),
    _DATAF(0.04550346732139587400),
    _DATAF(0.04679204523563385000),
    _DATAF(0.04809771478176116900),
    _DATAF(0.04942043498158454900),
    _DATAF(0.05076014995574951200),
    _DATAF(0.05211681500077247600),
    _DATAF(0.05349037423729896500),
    _DATAF(0.05488077551126480100),
    _DATAF(0.05628796666860580400),
    _DATAF(0.05771189928054809600),
    _DATAF(0.05915251374244689900),
    _DATAF(0.06060976162552833600),
    _DATAF(0.06208358332514762900),
    _DATAF(0.06357392668724060100),
    _DATAF(0.06508072465658187900),
    _DATAF(0.06660393625497818000),
    _DATAF(0.06814350187778472900),
    _DATAF(0.06969934701919555700),
    _DATAF(0.07127143442630767800),
    _DATAF(0.07285968959331512500),
    _DATAF(0.07446406036615371700),
    _DATAF(0.07608447968959808300),
    _DATAF(0.07772088795900344800),
    _DATAF(0.07937323302030563400),
    _DATAF(0.08104144036769866900),
    _DATAF(0.08272545784711837800),
    _DATAF(0.08442521095275878900),
    _DATAF(0.08614064753055572500),
    _DATAF(0.08787168562412262000),
    _DATAF(0.08961828052997589100),
    _DATAF(0.09138035029172897300),
    _DATAF(0.09315783530473709100),
    _DATAF(0.09495066851377487200),
    _DATAF(0.09675878286361694300),
    _DATAF(0.09858211129903793300),
    _DATAF(0.10042057186365128000),
    _DATAF(0.10227411240339279000),
    _DATAF(0.10414265841245651000),
    _DATAF(0.10602613538503647000),
    _DATAF(0.10792447626590729000),
    _DATAF(0.10983760654926300000),
    _DATAF(0.11176545172929764000),
    _DATAF(0.11370794475078583000),
    _DATAF(0.11566501110792160000),
    _DATAF(0.11763656884431839000),
    _DATAF(0.11962255835533142000),
    _DATAF(0.12162289768457413000),
    _DATAF(0.12363750487565994000),
    _DATAF(0.12566630542278290000),
    _DATAF(0.12770923972129822000),
    _DATAF(0.12976621091365814000),
    _DATAF(0.13183714449405670000),
    _DATAF(0.13392198085784912000),
    _DATAF(0.13602061569690704000),
    _DATAF(0.13813297450542450000),
    _DATAF(0.14025899767875671000),
    _DATAF(0.14239858090877533000),
    _DATAF(0.14455166459083557000),
    _DATAF(0.14671814441680908000),
    _DATAF(0.14889796078205109000),
    _DATAF(0.15109102427959442000),
    _DATAF(0.15329724550247192000),
    _DATAF(0.15551653504371643000),
    _DATAF(0.15774883329868317000),
    _DATAF(0.15999403595924377000),
    _DATAF(0.16225206851959229000),
    _DATAF(0.16452284157276154000),
    _DATAF(0.16680626571178436000),
    _DATAF(0.16910226643085480000),
    _DATAF(0.17141073942184448000),
    _DATAF(0.17373161017894745000),
    _DATAF(0.17606478929519653000),
    _DATAF(0.17841020226478577000),
    _DATAF(0.18076772987842560000),
    _DATAF(0.18313729763031006000),
    _DATAF(0.18551883101463318000),
    _DATAF(0.18791222572326660000),
    _DATAF(0.19031739234924316000),
    _DATAF(0.19273422658443451000),
    _DATAF(0.19516266882419586000),
    _DATAF(0.19760259985923767000),
    _DATAF(0.20005394518375397000),
    _DATAF(0.20251661539077759000),
    _DATAF(0.20499049127101898000),
    _DATAF(0.20747549831867218000),
    _DATAF(0.20997154712677002000),
    _DATAF(0.21247853338718414000),
    _DATAF(0.21499636769294739000),
    _DATAF(0.21752494573593140000),
    _DATAF(0.22006417810916901000),
    _DATAF(0.22261397540569305000),
    _DATAF(0.22517424821853638000),
    _DATAF(0.22774487733840942000),
    _DATAF(0.23032577335834503000),
    _DATAF(0.23291684687137604000),
    _DATAF(0.23551799356937408000),
    _DATAF(0.23812912404537201000),
    _DATAF(0.24075011909008026000),
    _DATAF(0.24338090419769287000),
    _DATAF(0.24602137506008148000),
    _DATAF(0.24867141246795654000),
    _DATAF(0.25133094191551208000),
    _DATAF(0.25399985909461975000),
    _DATAF(0.25667804479598999000),
    _DATAF(0.25936540961265564000),
    _DATAF(0.26206183433532715000),
    _DATAF(0.26476725935935974000),
    _DATAF(0.26748156547546387000),
    _DATAF(0.27020460367202759000),
    _DATAF(0.27293634414672852000),
    _DATAF(0.27567663788795471000),
    _DATAF(0.27842539548873901000),
    _DATAF(0.28118252754211426000),
    _DATAF(0.28394788503646851000),
    _DATAF(0.28672140836715698000),
    _DATAF(0.28950297832489014000),
    _DATAF(0.29229250550270081000),
    _DATAF(0.29508984088897705000),
    _DATAF(0.29789492487907410000),
    _DATAF(0.30070760846138000000),
    _DATAF(0.30352783203125000000),
    _DATAF(0.30635544657707214000),
    _DATAF(0.30919039249420166000),
    _DATAF(0.31203252077102661000),
    _DATAF(0.31488174200057983000),
    _DATAF(0.31773793697357178000),
    _DATAF(0.32060101628303528000),
    _DATAF(0.32347086071968079000),
    _DATAF(0.32634738087654114000),
    _DATAF(0.32923042774200439000),
    _DATAF(0.33211994171142578000),
    _DATAF(0.33501577377319336000),
    _DATAF(0.33791780471801758000),
    _DATAF(0.34082597494125366000),
    _DATAF(0.34374016523361206000),
    _DATAF(0.34666022658348083000),
    _DATAF(0.34958606958389282000),
    _DATAF(0.35251760482788086000),
    _DATAF(0.35545471310615540000),
    _DATAF(0.35839724540710449000),
    _DATAF(0.36134514212608337000),
    _DATAF(0.36429825425148010000),
    _DATAF(0.36725649237632751000),
    _DATAF(0.37021973729133606000),
    _DATAF(0.37318786978721619000),
    _DATAF(0.37616080045700073000),
    _DATAF(0.37913838028907776000),
    _DATAF(0.38212051987648010000),
    _DATAF(0.38510712981224060000),
    _DATAF(0.38809806108474731000),
    _DATAF(0.39109322428703308000),
    _DATAF(0.39409247040748596000),
    _DATAF(0.39709573984146118000),
    _DATAF(0.40010288357734680000),
    _DATAF(0.40311378240585327000),
    _DATAF(0.40612834692001343000),
    _DATAF(0.40914645791053772000),
    _DATAF(0.41216799616813660000),
    _DATAF(0.41519284248352051000),
    _DATAF(0.41822087764739990000),
    _DATAF(0.42125201225280762000),
    _DATAF(0.42428609728813171000),
    _DATAF(0.42732307314872742000),
    _DATAF(0.43036276102066040000),
    _DATAF(0.43340510129928589000),
    _DATAF(0.43644991517066956000),
    _DATAF(0.43949717283248901000),
    _DATAF(0.44254666566848755000),
    _DATAF(0.44559836387634277000),
    _DATAF(0.44865208864212036000),
    _DATAF(0.45170778036117554000),
    _DATAF(0.45476526021957397000),
    _DATAF(0.45782446861267090000),
    _DATAF(0.46088525652885437000),
    _DATAF(0.46394753456115723000),
    _DATAF(0.46701115369796753000),
    _DATAF(0.47007602453231812000),
    _DATAF(0.47314202785491943000),
    _DATAF(0.47620904445648193000),
    _DATAF(0.47927695512771606000),
    _DATAF(0.48234564065933228000),
    _DATAF(0.48541501164436340000),
    _DATAF(0.48848491907119751000),
    _DATAF(0.49155527353286743000),
    _DATAF(0.49462592601776123000),
    _DATAF(0.49769678711891174000),
    _DATAF(0.50076776742935181000),
    _DATAF(0.50383865833282471000),
    _DATAF(0.50690943002700806000),
    _DATAF(0.50997996330261230000),
    _DATAF(0.51305007934570313000),
    _DATAF(0.51611977815628052000),
    _DATAF(0.51918876171112061000),
    _DATAF(0.52225708961486816000),
    _DATAF(0.52532458305358887000),
    _DATAF(0.52839112281799316000),
    _DATAF(0.53145653009414673000),
    _DATAF(0.53452080488204956000),
    _DATAF(0.53758376836776733000),
    _DATAF(0.54064530134201050000),
    _DATAF(0.54370534420013428000),
    _DATAF(0.54676371812820435000),
    _DATAF(0.54982030391693115000),
    _DATAF(0.55287504196166992000),
    _DATAF(0.55592775344848633000),
    _DATAF(0.55897837877273560000),
    _DATAF(0.56202673912048340000),
    _DATAF(0.56507277488708496000),
    _DATAF(0.56811636686325073000),
    _DATAF(0.57115739583969116000),
    _DATAF(0.57419574260711670000),
    _DATAF(0.57723128795623779000),
    _DATAF(0.58026391267776489000),
    _DATAF(0.58329355716705322000),
    _DATAF(0.58631998300552368000),
    _DATAF(0.58934319019317627000),
    _DATAF(0.59236299991607666000),
    _DATAF(0.59537935256958008000),
    _DATAF(0.59839212894439697000),
    _DATAF(0.60140115022659302000),
    _DATAF(0.60440635681152344000),
    _DATAF(0.60740762948989868000),
    _DATAF(0.61040484905242920000),
    _DATAF(0.61339795589447021000),
    _DATAF(0.61638671159744263000),
    _DATAF(0.61937111616134644000),
    _DATAF(0.62235099077224731000),
    _DATAF(0.62532627582550049000),
    _DATAF(0.62829679250717163000),
    _DATAF(0.63126254081726074000),
    _DATAF(0.63422328233718872000),
    _DATAF(0.63717895746231079000),
    _DATAF(0.64012944698333740000),
    _DATAF(0.64307469129562378000),
    _DATAF(0.64601451158523560000),
    _DATAF(0.64894884824752808000),
    _DATAF(0.65187758207321167000),
    _DATAF(0.65480053424835205000),
    _DATAF(0.65771764516830444000),
    _DATAF(0.66062885522842407000),
    _DATAF(0.66353398561477661000),
    _DATAF(0.66643291711807251000),
    _DATAF(0.66932559013366699000),
    _DATAF(0.67221188545227051000),
    _DATAF(0.67509168386459351000),
    _DATAF(0.67796486616134644000),
    _DATAF(0.68083137273788452000),
    _DATAF(0.68369102478027344000),
    _DATAF(0.68654376268386841000),
    _DATAF(0.68938946723937988000),
    _DATAF(0.69222795963287354000),
    _DATAF(0.69505929946899414000),
    _DATAF(0.69788318872451782000),
    _DATAF(0.70069968700408936000),
    _DATAF(0.70350855588912964000),
    _DATAF(0.70630979537963867000),
    _DATAF(0.70910322666168213000),
    _DATAF(0.71188879013061523000),
    _DATAF(0.71466636657714844000),
    _DATAF(0.71743583679199219000),
    _DATAF(0.72019708156585693000),
    _DATAF(0.72295004129409790000),
    _DATAF(0.72569459676742554000),
    _DATAF(0.72843056917190552000),
    _DATAF(0.73115801811218262000),
    _DATAF(0.73387670516967773000),
    _DATAF(0.73658657073974609000),
    _DATAF(0.73928749561309814000),
    _DATAF(0.74197942018508911000),
    _DATAF(0.74466222524642944000),
    _DATAF(0.74733579158782959000),
    _DATAF(0.75000000000000000000),
    _DATAF(0.75265479087829590000),
    _DATAF(0.75530004501342773000),
    _DATAF(0.75793570280075073000),
    _DATAF(0.76056158542633057000),
    _DATAF(0.76317769289016724000),
    _DATAF(0.76578384637832642000),
    _DATAF(0.76837992668151855000),
    _DATAF(0.77096593379974365000),
    _DATAF(0.77354174852371216000),
    _DATAF(0.77610719203948975000),
    _DATAF(0.77866220474243164000),
    _DATAF(0.78120678663253784000),
    _DATAF(0.78374069929122925000),
    _DATAF(0.78626388311386108000),
    _DATAF(0.78877633810043335000),
    _DATAF(0.79127782583236694000),
    _DATAF(0.79376840591430664000),
    _DATAF(0.79624783992767334000),
    _DATAF(0.79871612787246704000),
    _DATAF(0.80117315053939819000),
    _DATAF(0.80361878871917725000),
    _DATAF(0.80605298280715942000),
    _DATAF(0.80847567319869995000),
    _DATAF(0.81088668107986450000),
    _DATAF(0.81328594684600830000),
    _DATAF(0.81567341089248657000),
    _DATAF(0.81804895401000977000),
    _DATAF(0.82041257619857788000),
    _DATAF(0.82276403903961182000),
    _DATAF(0.82510334253311157000),
    _DATAF(0.82743036746978760000),
    _DATAF(0.82974505424499512000),
    _DATAF(0.83204728364944458000),
    _DATAF(0.83433699607849121000),
    _DATAF(0.83661413192749023000),
    _DATAF(0.83887857198715210000),
    _DATAF(0.84113019704818726000),
    _DATAF(0.84336894750595093000),
    _DATAF(0.84559476375579834000),
    _DATAF(0.84780752658843994000),
    _DATAF(0.85000717639923096000),
    _DATAF(0.85219359397888184000),
    _DATAF(0.85436677932739258000),
    _DATAF(0.85652655363082886000),
    _DATAF(0.85867291688919067000),
    _DATAF(0.86080569028854370000),
    _DATAF(0.86292493343353271000),
    _DATAF(0.86503040790557861000),
    _DATAF(0.86712217330932617000),
    _DATAF(0.86920005083084106000),
    _DATAF(0.87126404047012329000),
    _DATAF(0.87331396341323853000),
    _DATAF(0.87534987926483154000),
    _DATAF(0.87737154960632324000),
    _DATAF(0.87937903404235840000),
    _DATAF(0.88137221336364746000),
    _DATAF(0.88335102796554565000),
    _DATAF(0.88531535863876343000),
    _DATAF(0.88726514577865601000),
    _DATAF(0.88920032978057861000),
    _DATAF(0.89112079143524170000),
    _DATAF(0.89302653074264526000),
    _DATAF(0.89491748809814453000),
    _DATAF(0.89679348468780518000),
    _DATAF(0.89865452051162720000),
    _DATAF(0.90050053596496582000),
    _DATAF(0.90233147144317627000),
    _DATAF(0.90414720773696899000),
    _DATAF(0.90594768524169922000),
    _DATAF(0.90773284435272217000),
    _DATAF(0.90950262546539307000),
    _DATAF(0.91125696897506714000),
    _DATAF(0.91299575567245483000),
    _DATAF(0.91471904516220093000),
    _DATAF(0.91642659902572632000),
    _DATAF(0.91811853647232056000),
    _DATAF(0.91979461908340454000),
    _DATAF(0.92145490646362305000),
    _DATAF(0.92309933900833130000),
    _DATAF(0.92472773790359497000),
    _DATAF(0.92634016275405884000),
    _DATAF(0.92793643474578857000),
    _DATAF(0.92951661348342896000),
    _DATAF(0.93108057975769043000),
    _DATAF(0.93262833356857300000),
    _DATAF(0.93415969610214233000),
    _DATAF(0.93567472696304321000),
    _DATAF(0.93717330694198608000),
    _DATAF(0.93865537643432617000),
    _DATAF(0.94012093544006348000),
    _DATAF(0.94156986474990845000),
    _DATAF(0.94300216436386108000),
    _DATAF(0.94441771507263184000),
    _DATAF(0.94581651687622070000),
    _DATAF(0.94719851016998291000),
    _DATAF(0.94856363534927368000),
    _DATAF(0.94991183280944824000),
    _DATAF(0.95124304294586182000),
    _DATAF(0.95255726575851440000),
    _DATAF(0.95385438203811646000),
    _DATAF(0.95513439178466797000),
    _DATAF(0.95639723539352417000),
    _DATAF(0.95764285326004028000),
    _DATAF(0.95887118577957153000),
    _DATAF(0.96008229255676270000),
    _DATAF(0.96127593517303467000),
    _DATAF(0.96245223283767700000),
    _DATAF(0.96361112594604492000),
    _DATAF(0.96475243568420410000),
    _DATAF(0.96587628126144409000),
    _DATAF(0.96698254346847534000),
    _DATAF(0.96807116270065308000),
    _DATAF(0.96914213895797729000),
    _DATAF(0.97019541263580322000),
    _DATAF(0.97123098373413086000),
    _DATAF(0.97224873304367065000),
    _DATAF(0.97324872016906738000),
    _DATAF(0.97423082590103149000),
    _DATAF(0.97519499063491821000),
    _DATAF(0.97614127397537231000),
    _DATAF(0.97706961631774902000),
    _DATAF(0.97797995805740356000),
    _DATAF(0.97887223958969116000),
    _DATAF(0.97974646091461182000),
    _DATAF(0.98060262203216553000),
    _DATAF(0.98144060373306274000),
    _DATAF(0.98226046562194824000),
    _DATAF(0.98306214809417725000),
    _DATAF(0.98384553194046021000),
    _DATAF(0.98461073637008667000),
    _DATAF(0.98535764217376709000),
    _DATAF(0.98608618974685669000),
    _DATAF(0.98679643869400024000),
    _DATAF(0.98748832941055298000),
    _DATAF(0.98816186189651489000),
    _DATAF(0.98881691694259644000),
    _DATAF(0.98945355415344238000),
    _DATAF(0.99007177352905273000),
    _DATAF(0.99067145586013794000),
    _DATAF(0.99125260114669800000),
    _DATAF(0.99181526899337769000),
    _DATAF(0.99235939979553223000),
    _DATAF(0.99288487434387207000),
    _DATAF(0.99339181184768677000),
    _DATAF(0.99388015270233154000),
    _DATAF(0.99434983730316162000),
    _DATAF(0.99480086565017700000),
    _DATAF(0.99523323774337769000),
    _DATAF(0.99564695358276367000),
    _DATAF(0.99604195356369019000),
    _DATAF(0.99641823768615723000),
    _DATAF(0.99677580595016479000),
    _DATAF(0.99711459875106812000),
    _DATAF(0.99743467569351196000),
    _DATAF(0.99773597717285156000),
    _DATAF(0.99801850318908691000),
    _DATAF(0.99828219413757324000),
    _DATAF(0.99852716922760010000),
    _DATAF(0.99875330924987793000),
    _DATAF(0.99896061420440674000),
    _DATAF(0.99914908409118652000),
    _DATAF(0.99931877851486206000),
    _DATAF(0.99946963787078857000),
    _DATAF(0.99960160255432129000),
    _DATAF(0.99971473217010498000),
    _DATAF(0.99980902671813965000),
    _DATAF(0.99988448619842529000),
    _DATAF(0.99994105100631714000),
    _DATAF(0.99997878074645996000),
    _DATAF(0.99999761581420898000),
};
