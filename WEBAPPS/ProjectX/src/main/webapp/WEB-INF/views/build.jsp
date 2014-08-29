<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
	<h2>Hello world</h2>
	<c:choose>
		<c:when test="${serviceAvailable}">
			Service available
		</c:when>
		<c:otherwise>
			Service not available
		</c:otherwise>
	</c:choose>
</body>
</html>
