<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<style type="text/css">
.ct-div {
	padding-left: 5%;
	margin-bottom: 20px;
}
</style>
</head>
<body>
	<h2>Simplest CI !</h2>
	<c:choose>
		<c:when test="${objectCanOpened}">
			<div class="ct-div">Service available</div>
			<div class="ct-div">
				Script content<br>
				<textarea rows="45" cols="100" name="objectContent"><c:out value="${objectContent}"></c:out></textarea>
			</div>
			<div class="ct-div">
				<a href='<c:url value="/home"></c:url>'>To home page</a>
			</div>
		</c:when>
		<c:otherwise>
			<div class="ct-div">File can't open on browser</div>
		</c:otherwise>
	</c:choose>
</body>
</html>