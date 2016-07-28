/*
  ==============================================================================

   This file is part of the ambix Ambisonic plug-in suite.
   Copyright (c) 2013/2014 - Matthias Kronlachner
   www.matthiaskronlachner.com
   
   Permission is granted to use this software under the terms of:
   the GPL v2 (or any later version)

   Details of these licenses can be found at: www.gnu.org/licenses

   ambix is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ==============================================================================
*/

// define normalization conversion
// until 10th order 3d

const float conv_norm_fuma_n3d [121] =
{
    1.4142135624	,
    1.7320508076	,
    1.7320508076	,
    1.7320508076	,
    1.9364916731	,
    1.9364916731	,
    2.2360679775	,
    1.9364916731	,
    1.9364916731	,
    2.0916500663	,
    3.4156502553	,
    2.2310934041	,
    2.6457513111	,
    2.2310934041	,
    1.9720265944	,
    2.0916500663	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000
};


const float conv_norm_sn3d_n3d [121] =
{
    1.0000000000	,
    1.7320508076	,
    1.7320508076	,
    1.7320508076	,
    2.2360679775	,
    2.2360679775	,
    2.2360679775	,
    2.2360679775	,
    2.2360679775	,
    2.6457513111	,
    2.6457513111	,
    2.6457513111	,
    2.6457513111	,
    2.6457513111	,
    2.6457513111	,
    2.6457513111	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.0000000000	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.3166247904	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.6055512755	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    3.8729833462	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.1231056256	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.3588989435	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	,
    4.5825756950	
};


const float conv_norm_fuma_sn3d [121] =
{
    1.4142135624	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    0.8660254038	,
    0.8660254038	,
    1.0000000000	,
    0.8660254038	,
    0.8660254038	,
    0.7905694150	,
    1.2909944487	,
    0.8432740427	,
    1.0000000000	,
    0.8432740427	,
    0.7453559925	,
    0.7905694150	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000
};


const float conv_norm_n3d_sn3d [121] =
{
    1.0000000000	,
    0.5773502692	,
    0.5773502692	,
    0.5773502692	,
    0.4472135955	,
    0.4472135955	,
    0.4472135955	,
    0.4472135955	,
    0.4472135955	,
    0.3779644730	,
    0.3779644730	,
    0.3779644730	,
    0.3779644730	,
    0.3779644730	,
    0.3779644730	,
    0.3779644730	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3333333333	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.3015113446	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2773500981	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2581988897	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2425356250	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2294157339	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902	,
    0.2182178902
};


const float conv_norm_sn3d_fuma [121] =
{
    0.7071067812	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.1547005384	,
    1.1547005384	,
    1.0000000000	,
    1.1547005384	,
    1.1547005384	,
    1.2649110641	,
    0.7745966692	,
    1.1858541226	,
    1.0000000000	,
    1.1858541226	,
    1.3416407865	,
    1.2649110641	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000
};


const float conv_norm_n3d_fuma [121] =
{
    0.7071067812	,
    0.5773502692	,
    0.5773502692	,
    0.5773502692	,
    0.5163977795	,
    0.5163977795	,
    0.4472135955	,
    0.5163977795	,
    0.5163977795	,
    0.4780914437	,
    0.2927700219	,
    0.4482107285	,
    0.3779644730	,
    0.4482107285	,
    0.5070925528	,
    0.4780914437	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000	,
    1.0000000000
};

const float conv_norm_ones [121] =
{
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0	,
    1.0
};
