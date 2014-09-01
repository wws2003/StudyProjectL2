<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<style type="text/css">
.ct-div {
	padding-left: 5%;
}
</style>
</head>
<body>
	<h2>Simplest CI !</h2>
	<div class="ct-div" style="margin-bottom: 30px;">
		A sample project to support CI for my program solving the problem of
		Parallel Particles <a
			href="http://www.eecs.berkeley.edu/~carazvan/2010bootcamp/index.html">Here</a>
		<br> It would support visualization of the result of the program on
		user-browser soon...
	</div>
	<div class="ct-div ">
		<div style="margin-bottom: 20px;">
			A list of all build tasks so far: <br> <a
				href="<c:url value="/buildlist"></c:url>"><c:url
					value="/buildlist"></c:url></a>
		</div>
		<div>
			You can test this webapp by adding 5 build tasks and waiting for them to be
			built. The auto-build can also be triggered by a Git push hook: <br>
			<a href="<c:url value="/testbuild/5"></c:url>"><c:url
					value="/testbuild/5"></c:url></a>
		</div>
	</div>
</body>
</html>
