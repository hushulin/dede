$(function() {
	$('.png').each(function() {
		$(this).css({
			'filter': 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src="' +
			$(this).attr('src') +
			'", sizingMethod="scale");'
		});
	});
});