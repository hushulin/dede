<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><div class="header_w">
  <div class="header">
    <h1 class="logo"><a href="/" title=""><img src="/skin/images/logo.png" class="png" width="283" height="56" alt="<?php echo $GLOBALS['cfg_webname']; ?>" style="margin-top:13px;"></a></h1>
    <div class="nav">
      <ul class="clearfix">
        <li class=""><a href="/" title="">网站首页</a></li>
        <?php
$atts = array();
$atts['tagname'] = 'channel';
$atts['type'] = 'top';
$atts['row'] = '5';
$atts['currentstyle'] = '<li class=\'current\'><a href=\'~typelink~\' ~rel~><span>~typename~</span></a></li>';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{
?>
        <li><a href="[field:typeurl/]" title="">[field:typename/]</a></li>
         <?php
}
}
?>
      </ul>
      <div class="navBg"></div>
    </div>
    <div class="header_call"> <img src="/skin/images/call.png" class="png" width="183" height="32" alt=""> </div>
  </div>
</div>