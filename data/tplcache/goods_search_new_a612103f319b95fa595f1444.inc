<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<link rel="stylesheet" href="/skin/work/css/bootstrap.min.css">
		<title>验证 - <?php echo $cfg_webname;?></title>
	</head>
	<body>
	<div class="container">


  <form action="/plus/advancedsearch.php" method="post">
    <input type="hidden" name="mid" value="6" />
    <div class="form-group row">
      <div class="col-xs-10">
        <input type="text" class="form-control" name="goodsn" value="" placeholder="请输入查询的商品编号" />
      </div>
        <button type="submit" class="btn btn-primary col-xs-1">查询</button>
    </div>
  </form>

  <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{

  $fields['stime'] = GetDateTimeMk($fields['senddate']);
  $fields['arcurl'] = GetArcUrl($fields['aid'],$fields['typeid'],$fields['senddate'],$fields['title'],$fields['ismake'],$fields['arcrank'],$fields['namerule'],$fields['typedir'],$fields['money']);
  $fields['typeurl'] = GetTypeUrl($fields['typeid'],MfTypedir($fields['typedir']),$fields['isdefault'],$fields['defaultname'],
        $fields['ispart'],$fields['namerule2'],$fields['moresite'],$fields['siteurl'],$fields['sitepath']);
  ?>

  <div class="panel panel-primary">
    <div class="panel-heading">
      <h3 class="panel-title">您查询的产品编号：<?php echo $fields['goodsn']; ?> 以下是查询结果:</h3>
    </div>
    <div class="panel-body">
      <!--该产品编号查询无结果，请确认编号是否正确.-->
      <img src="<?php echo $fields['litpic']; ?>" alt="..." class="img-thumbnail">
      <p>档案查询编码：<span class="text-danger"><?php echo $fields['goodsn']; ?></span></p>
      <p>原木材名称：<span class="text-danger"><a href="<?php echo $fields['arcurl']; ?>" target="_blank"><?php echo $fields['title']; ?></a></span></p>
      <p>藏品类别名称：<span class="text-danger"><a href="<?php echo $fields['typeurl']; ?>" target="_blank"><?php echo $fields['typename']; ?></a></span></p>
      <p>价格:<span class="text-danger"><?php echo $fields['trueprice']; ?></span></p>
      <p>点击:<span class="text-danger"><?php echo $fields['click']; ?></span></p>
      <p>日期:<span class="text-danger"><?php echo $fields['stime']; ?></span></p>
<!--
      <h4 class="text-primary">收藏证书</h4>
      <img src="http://pic14.nipic.com/20110522/7411759_164157418126_2.jpg" alt="..." class="img-thumbnail">
 -->
    </div>
  </div>

  <?php
}
}?>


  </div>
	</body>
</html>