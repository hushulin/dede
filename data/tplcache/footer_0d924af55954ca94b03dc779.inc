<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><div class="footerInfo_w">
  <div class="footerInfo">
    <div class="footerInfo_link"> <?php
$atts = array();
$atts['tagname'] = 'channel';
$atts['type'] = 'top';
$atts['row'] = '10';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{
?> <a href="[field:typeurl/]" title="">[field:typename/]</a>  | 
      <?php
}
}
?> <a href="http://www.41ty.com/" title="">天鹰模板</a> </div>
    <div class="footerInfo_about">
      <p><?php echo $GLOBALS['cfg_webname']; ?></p>
      <p>公司地址：<?php echo $GLOBALS['cfg_dz']; ?></p>
      <p>公司电话：<?php echo $GLOBALS['cfg_tel']; ?></p>
    </div>
    <div class="link_btn">
      <ul>
        <li><a target="_blank" href="http://wpa.qq.com/msgrd?v=1&uin=123456&site=qq&menu=yes" title="" class="link_qq"></a></li>
        <li><a target="_blank" href="http://e.weibo.com/" title="" class="link_sina"></a></li>
        <li class="link_weixin_li"><a href="javasctipt:void(0);" title="" class="link_weixin"></a>
          <div class="link_weixin_ewm" style=""> <img src='/skin/images/54b2bd2677dce.jpg' width="130" height="130" alt=""> </div>
        </li>
      </ul>
    </div>
  </div>
</div>
<div class="footer_w">
  <div class="footer clearfix">
    <div class="footer_copy">Copyright © 2015 41天鹰模板（www.41ty.com） 版权所有  <?php echo $GLOBALS['cfg_beian']; ?> </div>
    <div class="footer_link"> <a href="/a/qiyejianjie/" title="">关于我们</a>  |   <a href="/a/lianxiwomen/" title="">联系我们</a>  |   <a href="javascript:void(0);" title="">网站统计</a> </div>
  </div>
</div>
<div class="fixedBox"> <a target="_blank" href="http://wpa.qq.com/msgrd?v=1&uin=329435598&site=qq&menu=yes" title=""><img src="/skin/images/qq.png" class="png" width="67" height="65" alt=""></a> </div>