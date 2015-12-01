$(function(){
	$(".link_weixin_li").hover(function(){
		$(this).find(".link_weixin_ewm").stop().animate({"height":"130px"},300)
	},function(){
		$(this).find(".link_weixin_ewm").stop().animate({"height":"0"},300)
	})
	$(".in_serviceShow_colse").click(function(){
		$(this).parent().hide();
		$(".blackBg").hide();
	})
	$(".fancybox").click(function(){
		var href = $(this).attr("href");
		$(href).show();
		$(".blackBg").show();
		return false;
	})
})
function Tabs(showObj,togglesObj,eventObj,className){
	var togglesObject = $(togglesObj);
	togglesObject.on(eventObj,function(){
		var index = $(this).index();
		var thisId = $(this).parent().attr("id");
		togglesObject.removeClass(className).eq(index).addClass(className);
		$("#"+thisId+"_con").find(showObj).removeClass(className).hide().eq(index).addClass(className).show();
	})
}
(function($){
	$.fn.movebg=function(options){
		var defaults={
		width:120,
		extra:50,
		speed:300,
		rebound_speed:300
	};
	var defaultser=$.extend(defaults,options);
	return this.each(function(){
		var _this=$(this);
		var _item=_this.children("ul").children("li").children("a");
		var origin=_this.children("ul").children("li.current").index();
		var _mover=_this.find(".navBg");
		var hidden;
		if (origin==-1){origin=0;hidden="1"} else{_mover.show()};
		var cur=prev=origin;
		var extra=defaultser.extra;
		_mover.css({left:""+defaultser.width*origin+"px"});
		
		_item.each(function(index,it){
			$(it).mouseover(function(){
				cur=index;
				move();
				prev=cur;
			});
		});
		_this.mouseleave(function(){
			cur=origin;
			move();
			if(hidden==1){_mover.stop().fadeOut();}
		});
		
		function move(){
			_mover.clearQueue();
			if(cur<prev){extra=-Math.abs(defaultser.extra);}
			else{extra=Math.abs(defaultser.extra)};
			_mover.queue(
				function(){
					$(this).show().stop(true,true).animate({left:""+Number(cur*defaultser.width+extra)+""},defaultser.speed),
					function(){$(this).dequeue()}
				}
			);
			_mover.queue(
				function(){
					$(this).stop(true,true).animate({left:""+cur*defaultser.width+""},defaultser.rebound_speed),
					function(){$(this).dequeue()}
				}
			);
		};
	})
	}
})(jQuery);
$.fn.slide = function(options) {
	var defaults = {
		type:         'left',
		btn:          '.slide_btn',
		leftBtn:      '.slide_left',
		rightBtn:     '.slide_right',
		btnActive:    'click',
		picBox:       '.slide_pic',
		num:          '1',
		conWidth:     '100%',
		conHeidth:    '100%',
		time:         '3000',
		speed:        '500',
		play:         '1',
		percent:      '0'
	};
	var
		obj       =     $.extend(defaults,options),
		self      =     $(this),
		picUl     =     self.find(obj.picBox+">ul"),
		picLi     =     self.find(obj.picBox+">ul>li"),
		btnLi     =     self.find(obj.btn+">ul>li"),
		leftBtn   =     self.find(obj.leftBtn),
		rightBtn  =     self.find(obj.rightBtn),
		type      =     obj.type,
		conWidth  =     obj.conWidth,
		conHeight  =    obj.conHeight,
		speed     =     obj.speed,
		percent   =     obj.percent,
		len       =     Math.ceil(picLi.length/obj.num),
		index     =     0,
		lose   =   0,
		timer;

	if(percent == 1 && type == "left"){
		picUl.css({"width":100*len+"%"});
		picLi.css({"width":100/len+"%"});
		$(this).animate({"opacity":"1"},500);
	}
	if(percent == 2 && type == "fade"){
		$(".opacity").css({opacity: 0});
		lose   =   0;
		In_1();
	}
	btnLi.bind(obj.btnActive,function(){
		if(index != btnLi.index(this)){
			index = btnLi.index(this);
			goanimate(index);
		}
	})

	leftBtn.click(function(){
		if(lose == 0){
			if(index==0){index=len-1;}else{index--;}
			goanimate(index);
		}
	})

	rightBtn.click(function(){
		if(lose == 0){
			if(index==len-1){index=0;}else{index++;}
			goanimate(index);
		}
	})

	if(obj.play==1){
		clearInterval(timer);
		timer = setInterval(function(){
			if(lose == 0){
				if(index==len-1){index=0;}else{index++;}
				goanimate(index);
			}
		},obj.time);
		self.mousedown(function(){
			clearInterval(timer);
		});
		self.mouseup(function(){
			timer = setInterval(function(){
				if(lose == 0){
					if(index==len-1){index=0;}else{index++;}
					goanimate(index);
				}
			},obj.time);
		});
	}
	var goanimate = function(index){
		if(percent == "1" && type == "left"){
			picUl.stop().animate({"marginLeft":-index*100 +"%"},speed);
		}
		if(percent == "0" && type == "left"){
			picUl.stop().animate({"marginLeft":-index*conWidth},speed);
		}
		if(percent == "0" && type == "top"){
			picUl.stop().animate({"marginTop":-index*conHeight},speed);
		}
		if(percent == "0" && type == "fade"){
			picLi.stop(false,true).fadeOut(speed);
			picLi.eq(index).stop(false,true).fadeIn(speed);
		}
		if(percent == "2" && type == "fade"){
			lose   =   1 ;
			picLi.stop(false,true).fadeOut(speed);
			picLi.eq(index).stop(false,true).fadeIn(speed);
			$(".opacity").animate({opacity: 0},500);
			if(index == 0){
				lose = 0
			}else if(index == 1){
				In_3();
			}else if(index == 2){
				In_2();
			}else if(index == 3){
				In_1();
			}
		}
		btnLi.removeClass("active").eq(index).addClass("active");
	}
	function In_1(){
		lose = 1;
		setTimeout(function() {
			$(".in_bannerText1").css({top:"104px",opacity: 0});
			$(".in_bannerText1_title").css({left:"160px",opacity: 0});
			$(".in_bannerText1_about").css({left:"160px",opacity: 0});
			$(".in_bannerText1").animate({opacity: 1,top:"270px"},1000,function(){
				$(".in_bannerText1_title").animate({opacity: 1,left:"0"},600);
				setTimeout(function() {
					$(".in_bannerText1_about").animate({opacity: 1,left:"0"},600,function(){
						lose = 0;
					});
				},250);
			});
		},50);
	}
	function In_2(){
		lose = 1;
		setTimeout(function() {
			$(".in_bannerText2").css({left:"-1340px",opacity: 0});
			$(".in_bannerText2_title1").css({left:"100px",opacity: 0});
			$(".in_bannerText2_title2").css({left:"160px",opacity: 0});
			$(".in_bannerText2").animate({opacity: 1,left:"0"},1000,function(){
				$(".in_bannerText2_title1").animate({opacity: 1,left:"0"},600);
				setTimeout(function() {
					$(".in_bannerText2_title2").animate({opacity: 1,left:"0"},function(){
						lose = 0;
					});
				},250);
			});
		},50);
	}
	function In_3(){
		lose = 1;
		setTimeout(function() {
			
			$(".in_bannerText3").css({right:"-1125px",opacity: 0});
			$(".in_bannerText3_title").css({right:"80px",opacity: 0});
			$(".in_bannerText3").animate({opacity: 1,right:"0"},1000,function(){
				$(".in_bannerText3_title").animate({opacity: 1,right:"0"},function(){
					lose = 0;
				});
			});
		},50);
	}
}