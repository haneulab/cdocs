# Web Guide Session 1 Content

Today, we've discussed the fundamental use of `HTML`, `CSS` and `JavaScript` and how these types of files need to be called inside the `html` file to be served as a web application.

## Source Code

```html
<!-- index.html file -->
<!DOCTYPE html>
<html>
  <head>
    <!-- tags inside head tags can be used a meta data for SEO (search engine optimization) or adding `title` and `style` tags -->
    <!-- these tags are meta tags and nothing to do with displaying contents (like text and images) -->
    <title>Welcome to My Portfolio</title>
    <style>
      /* We need to use CSS syntax here */
      * {
        margin: 0;
        padding: 0;
      }

      div,
      section {
        margin: 40px;
        width: 200px;
        height: 200px;
        padding: 20px;
        background: wheat;
        border: 1px solid red;
        font-size: 20px;
      }
    </style>
  </head>

  <body>
    <!-- tags inside the body tags are UI implementations meaning they will be displayed to users -->
    <div>I am a div</div>
    <section>I am a div</section>

    <script>
      // we need use JavaScript Syntax here...
      function addTwoNums(a, b) {
        console.log(a + b);
      }
```
