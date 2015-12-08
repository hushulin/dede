<?php
$z[0]=Array("field","",66,85);
$z[0][4]['name']="title";
$z[1]=Array("global","",86,112);
$z[1][4]['name']="cfg_webname";
$z[2]=Array("field","",153,182);
$z[2][4]['name']="keywords";
$z[3]=Array("field","",222,280);
$z[3][4]['name']="description";
$z[3][4]['function']="html2text(@me)";
$z[4]=Array("include","",782,817);
$z[4][4]['filename']="head.htm";
$z[5]=Array("list","\r\n    <li> <a href=\"[field:arcurl/]\" title=\"\">\r\n      <div class=\"subnews_about\">\r\n        <h3>[竣工资讯][field:title/]</h3>\r\n        <p>[field:description function='cn_substr(@me,250)'/]...</p>\r\n      </div>\r\n      <div class=\"subnews_img\"> <img src=\"/skin/images/nopic.jpg\" alt=\"\"> </div>\r\n      </a> </li>\r\n    ",1257,1612);
$z[5][4]['pagesize']="20";
$z[6]=Array("include","",1679,1716);
$z[6][4]['filename']="footer.htm";

?>