<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title><?php echo $fields['title']; ?>_<?php echo $GLOBALS['cfg_webname']; ?></title>
<meta name="keywords" content="<?php echo $fields['keywords']; ?>" />
<meta name="description" content="<?php echo html2text($fields['description']); ?>" />
<meta name="viewport"content="width=1200, initial-scale=1"/>
<link href="/skin/css/style.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="/skin/js/jquery-1.11.1.min.js"></script>
<script type="text/javascript" src="/skin/js/ainatec.js"></script>
<!--[if lte IE 6]>
    <script src="js/png.js" type="text/javascript"></script>
    <script type="text/javascript">
        DD_belatedPNG.fix('.png');
    </script>
<![endif]-->
</head>
<body class="pageBg">

<?php include $this->CompilerInclude("head.htm");
 ?>
<div class="clear" style="height:82px"></div>
<script>
$(function(){
	$(".nav").movebg({
		width:116,
		extra:0,
		speed:300,
		rebound_speed:400
	});
})
</script>
<div class="contentTitle_w">
  <div class="contentTitle clearfix">
    <h2 class="contentTitle_name">NEWS</h2>
    <div class="contentTitle_menu">
      <ul class="clearfix">
      </ul>
    </div>
  </div>
</div>
<form action="/plus/advancedsearch.php" method="post"><input type="hidden" name="mid" value="6" /><input type="hidden" name="dopost" value="search" />关键词：<input type="text" name="q" /><br />唯一编号 : <input type="text" name="goodsn" value="" /><br /><input type="submit" name="submit" value="开始搜索" /></form>
<?php
$atts = array();
$atts['tagname'] = 'list';
$atts['perpage'] = '4';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{

}
}
?>
<div class="subnews_list">
  <ul>
    <?php
$atts = array();
$atts['tagname'] = 'list';
$atts['pagesize'] = '20';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{
?>
    <li> <a href="[field:arcurl/]" title="">
      <div class="subnews_about">
        <h3>[竣工资讯][field:title/]</h3>
        <p>[field:description function='cn_substr(@me,250)'/]...</p>
      </div>
      <div class="subnews_img"> <img src="/skin/images/nopic.jpg" alt=""> </div>
      </a> </li>
    <?php
}
}
?>
  </ul>
</div>
<div class="clear" style="height:80px;"></div>
<?php include $this->CompilerInclude("footer.htm");
 ?>
</body>
</html>